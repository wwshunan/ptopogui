#include "LeapFrog.h"
#include <iostream>

void LeapFrog::Update(double timeStep, Beam &beam)
{
  int    particleNumber = beam.particle.size();
//#pragma omp for
  for(int i=0;i<particleNumber;++i)
  {
    double xTemp =0,yTemp=0,zTemp=0;
    double cc=0,megnField=0;
    if(beam.particle[i].lossFlag)
    {
      continue;
    }

    //1:half-step accleration in the electric field
    for(int j=0;j<3;++j)
    {
      beam.particle[i].xyz[2*j+1]+=beam.particle[i].totalElecField[j]*timeStep/2;         //unit:m/s
    }

    //2:particle velocity rotate in magnetic field
    megnField=sqrt(pow(beam.particle[i].totalMegnField[0],2) + pow(beam.particle[i].totalMegnField[1],2) + pow(beam.particle[i].totalMegnField[2],2));


    // try to modify the following with eigen lib as a form of matrix multiply vector.

    if(megnField>1e-10)
    {
      cc=1.0/(1+pow(timeStep/2,2)*pow(megnField,2));

      xTemp=beam.particle[i].xyz[1];
      yTemp=beam.particle[i].xyz[3];
      zTemp=beam.particle[i].xyz[5];
      
      beam.particle[i].xyz[1] = cc*(
          ( 1 + pow(timeStep/2,2) * ( pow(beam.particle[i].totalMegnField[0],2) - pow(beam.particle[i].totalMegnField[1],2) - pow(beam.particle[i].totalMegnField[2],2) ) ) * xTemp
          +     timeStep*(      beam.particle[i].totalMegnField[2]+beam.particle[i].totalMegnField[0]*beam.particle[i].totalMegnField[1]*timeStep/(2)  )       *       yTemp
          +     timeStep*((-1)* beam.particle[i].totalMegnField[1]+beam.particle[i].totalMegnField[0]*beam.particle[i].totalMegnField[2]*timeStep/(2)  )       *       zTemp);

      beam.particle[i].xyz[3] = cc*(
                timeStep*((-1)* beam.particle[i].totalMegnField[2]+beam.particle[i].totalMegnField[0]*beam.particle[i].totalMegnField[1]*timeStep/(2)  )       *       xTemp
          +(1 + pow(timeStep/2,2) * (-pow(beam.particle[i].totalMegnField[0],2) + pow(beam.particle[i].totalMegnField[1],2) - pow(beam.particle[i].totalMegnField[2],2) ) ) * yTemp
          +     timeStep*(      beam.particle[i].totalMegnField[0]+beam.particle[i].totalMegnField[1]*beam.particle[i].totalMegnField[2]*timeStep/(2)  )       *       zTemp);

      beam.particle[i].xyz[5] = cc*(
                timeStep*(      beam.particle[i].totalMegnField[1]+beam.particle[i].totalMegnField[0]*beam.particle[i].totalMegnField[2]*timeStep/(2)  )       *       xTemp
          +     timeStep*((-1)* beam.particle[i].totalMegnField[0]+beam.particle[i].totalMegnField[1]*beam.particle[i].totalMegnField[2]*timeStep/(2)  )       *       yTemp
          +(1 + pow(timeStep/2,2) * ( pow(beam.particle[i].totalMegnField[2],2) - pow(beam.particle[i].totalMegnField[0],2) - pow(beam.particle[i].totalMegnField[1],2) ) ) * zTemp);
    }
    //3:curvilinear accleration
    //This is a linac disign,so the R is infinite,so this step won't make any change

    //4:half-step accleration in the electric field again
    for(int j=0;j<3;++j)
    {
      beam.particle[i].xyz[2*j+1]+=beam.particle[i].totalElecField[j] * timeStep/2;       //unit:m/s
    }

    //5:advance the position
    beam.particle[i].xyz[0] += beam.particle[i].xyz[1]*timeStep;                  //unit:m
    beam.particle[i].xyz[2] += beam.particle[i].xyz[3]*timeStep;
    beam.particle[i].xyz[4] += beam.particle[i].xyz[5]*timeStep;
  }
}

