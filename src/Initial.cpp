#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cfloat>

#include "Beam.h"
#include "Lattice.h"
#include "Initial.h"
#include "Distribution.h"
#include "MyFunc.h"
#include "AllElement.h"
#include "Global.h"

using namespace std;

int Initial::Read(const MainWindow& mw)
{
    method = mw.archMap[mw.architect];
    internalFieldMethod = mw.scModelMap[mw.scModel];
    dimension = mw.meshDim + 2;
    distributionType.at(0) = mw.disMap[mw.transDis];
    distributionType.at(1) = mw.disMap[mw.longDis];
    numofCharge = mw.chargeNum;
    numofMass = mw.massNum;
    particleNumber = mw.particleNum;

    emitx = mw.emitX;
    betax = mw.betaX;
    alphax = mw.alphaX;
    emity = mw.emitY;
    betay = mw.betaY;
    alphay = mw.alphaY;
    emitz = mw.emitZ;
    betaz = mw.betaZ;
    alphaz = mw.alphaZ;
    twiss[0] = mw.emitX;
    twiss[1] = mw.betaX;
    twiss[2] = mw.alphaX;
    twiss[3] = mw.emitY;
    twiss[4] = mw.betaY;
    twiss[5] = mw.alphaY;
    twiss[6] = mw.emitZ;
    twiss[7] = mw.betaZ;
    twiss[8] = mw.alphaZ;

    displacePos[0] = mw.dx;
    displacePos[1] = mw.dy;
    displacePos[2] = mw.dz;
    displaceDPos[0] = mw.dxPrime;
    displaceDPos[1] = mw.dyPrime;
    displaceDPos[2] = mw.dzPrime;

    frequency = mw.freq;
    KneticE = mw.kEnergy; 
    numofGrid[0] = mw.xDim;
    numofGrid[1] = mw.yDim;
    numofGrid[2] = mw.zDim;
    current = mw.current;
    if (current < DBL_EPSILON) {
        spaceChargeFlag	= false;
    } else {
        spaceChargeFlag = true;
    }
    pusher = mw.pusherMap[mw.pusher];
    stepPerCycle = mw.stepNumPerCycle;
    maxStepNumber = mw.maxStepNum;
}

int Initial::InitParticle(Beam &beam, const MainWindow& mw)
{
  cout << "xxx" << endl;
  Read(mw);
  beam.particleNumber   =this->particleNumber;
  beam.frq              =frequency;
  
  beam.particle         .resize(particleNumber);
  beam.eGamma           .resize(particleNumber);
  beam.eBeta            .resize(particleNumber);
  beam.eBetaGamma       .resize(particleNumber);
  beam.dw               .resize(particleNumber);
  beam.phi              .resize(particleNumber);
  
  double gamma          =       1.0+KneticE/(BaseMassInMeV*numofCharge); // devided by numofCharge
  double beta           =       sqrt(1-1.0/gamma/gamma);
  double speed          =       beta*C_light;
  double macroNumber;
  if(spaceChargeFlag)
  {
    macroNumber    =       current  / frequency  / particleNumber / (numofCharge *BaseCharge); 
  }
  else
  {
    macroNumber    =1;
  }
  
    cout << twiss[0] << "xxx"<<endl;
  twiss[0]=twiss[0]/(beta*gamma)*4;
  twiss[3]=twiss[3]/(beta*gamma)*4;
  twiss[6]=twiss[6]/(beta*pow(gamma,3))*4;
  cout<<"Gamma   =  "<<gamma<<"\nBeta    =  "<<beta<<"\nSpeed   =  "<<(beta*C_light)<<endl;
  cout<<"beam.particleNumber="<<this->particleNumber<<"\nemitx="<<twiss[0]<<endl;
  cout<<"frequency is "<<frequency<<endl;


  cout << displaceDPos[0] << " " << displaceDPos[1] << " " << displaceDPos[2] << endl;
cout << displacePos[0] << " " << displacePos[1] << " " << displacePos[2] << endl;
  vector<vector<double> > xyz(particleNumber,vector<double>(6));
  cout << twiss[0] << " " << twiss[3] << " " << twiss[6] << endl;
  if(     distributionType[0]=="KV")
  {
    KV2DTwiss(twiss,xyz);             //distribution is not a decleared as Class in Distribution.h
  }
  else if(distributionType[0]=="WB")
  {
    //WB3D(beam);
  }
  else if(distributionType[0]=="GS")
  {
    //GS3D(beam);
  }
  else if(distributionType[0]=="PB")
  {
    //PB3D(beam);
  }
  else
  {
    //do nothing
  }
  for(int i=0;i<particleNumber;++i)
  {
    for(int j=0;j<4;++j)
    {
      beam.particle[i].xyz[j] = xyz[i][j];
    }
    beam.particle[i].indexElem        = 0;
    beam.particle[i].transLossFlag    = 0;
    beam.particle[i].longiLossFlag    = 0;
    beam.particle[i].lossFlag         = 0;
    beam.particle[i].charge           = macroNumber * numofCharge * BaseCharge;
    beam.particle[i].mass             = macroNumber * numofMass   * BaseMass;
  }
  if(dimension==3)
  {
    vector<double> twissLongi(9);
    for(int i=0;i<3;++i)
    {
      twissLongi[i]=twiss[i+6];
      twissLongi[i+3]=twiss[i+6];
    }
    if( distributionType[1]=="KV")
    {
      KV2DTwiss(twissLongi,xyz);
    }
    else if(distributionType[1]=="WB")
    {
      //WB2D(beam);
    }
    else if(distributionType[1]=="GS")
    {
      //GS2D(beam);
    }
    else if(distributionType[1]=="PB")
    {
      //PB2D(beam);
    }
    else
    {
      //do nothing
    }

    for(int i=0;i<particleNumber;++i)
    {
      for(int j=0;j<2;++j)
      {
        beam.particle[i].xyz[j+4] = xyz[i][j];
      }
    }
  }


  //  double gammatemp,betatemp;
  //  default_random_engine generator;
  //  uniform_real_distribution<double> distribution2(1-dw,1+dw);
  double temp;
  for(int i=0;i<particleNumber;i++) 
  {
    beam.particle[i].xyz[0] = beam.particle[i].xyz[0]           + displacePos [0];
    beam.particle[i].xyz[1] = beam.particle[i].xyz[1] * speed   + displaceDPos[0];
    beam.particle[i].xyz[2] = beam.particle[i].xyz[2]           + displacePos [1];
    beam.particle[i].xyz[3] = beam.particle[i].xyz[3] * speed   + displaceDPos[1];
    beam.particle[i].xyz[4] = beam.particle[i].xyz[4]           + displacePos [2];
    temp                    = pow((beam.particle[i].xyz[5]+1.0) * beta*gamma , 2);
    beam.particle[i].xyz[5] = sqrt( temp/(1.0+temp) ) * C_light + displaceDPos[2];
    //beam.particle[i].xyz[5]=distribution2(generator)*Ebeta*C_light;
  }


  int particleOutFlag=1;
  if(particleOutFlag)
  {
    ofstream pout("particle.out");
    pout<<setiosflags(ios::showpos);
    pout.setf(ios::showpoint);
    for(int i = 0;i<beam.particle.size();++i)
    {
      for(int j =0;j<6;++j)
      {
        pout<<setw(20)<<setiosflags(ios::scientific)<<setprecision(12)<<beam.particle[i].xyz[j]<<"   "; 
      }
      pout<<endl;
    }
  }
    beam.CaculateEmittance();

    double a1 = -0.301130618617947      * 1.240577278842173E-003 * 1.610993536443865E-003;
    double a2 = -0.301130618617947      * 1.240577278842173E-003 * 1.610993536443865E-003;
    double a3 = 7.071103757052691E-004  * 3.243090866957798E-002 * 1.292498165462169E-003;
    vector<double> tempv{
    pow(1.240577278842173E-003,2), pow(1.610993536443865E-003,2), a1,
    pow(1.240577278842173E-003,2), pow(1.610993536443865E-003,2), a2,
    pow(3.243090866957798E-002,2), pow(1.292498165462169E-003,2), a3};
    GS3DSigma(tempv,xyz);

  double sum2=0,sum22=0;
  if(particleOutFlag)
  {
    ofstream pout("particle.out");
    pout<<setiosflags(ios::showpos);
    pout.setf(ios::showpoint);
    for(int i = 0;i<beam.particle.size();++i)
    {
      for(int j =0;j<6;++j)
      {
        pout<<setw(20)<<setiosflags(ios::scientific)<<setprecision(12)<<xyz[i][j]<<"   "; 
      }
      sum2+=xyz[i][0]*xyz[i][0];
      sum22+=xyz[i][2]*xyz[i][2];
      pout<<endl;
    }
  }
  cout<<sqrt(sum2/beam.particle.size())<<"   "<<sqrt(sum22/beam.particle.size())<<endl;
  
  
  cout<<"press any key to continue..."<<endl;
  getchar();
  return 0;
}

int Initial::InitLattice(Lattice &lattice)
{
  ifstream infile("lattice.txt");
  if(!infile.is_open())
  {
    cout<<"Error! Cannot open \"lattice.txt\".\nexit."<<endl;
    exit(0);
  }
  vector<string>        strVec;
  string                str;
  cout<<"initial lattice"<<endl;
  while(infile.peek()!=EOF)
  {
    getline(infile,str);
    StringSplit(str,strVec);   //element information is store in serVec
    if(strVec.size()==0)
    {
      continue;
    }

    if(strVec.size()<4)
    {
      cout<<"Error! parameter error in: "<<str<<endl;
      continue;
    }

    if(strVec[0]=="drift")
    {
      Element *ele      = new Drift;
      lattice.SetElement(strVec,ele);
      ele   = NULL;
    }
    else if(strVec[0]=="quadm")
    {
      Element *ele      = new Quadrupole;
      lattice.SetElement(strVec,ele);
      ele   = NULL;
    }
    else if(strVec[0]=="rfq")
    {    
      Element *ele      = new RFQ;
      lattice.SetElement(strVec,ele);
      ele   = NULL;               
    }
    else if(strVec[0]=="field")
    {
      Element *ele      = new Field;
      lattice.SetElement(strVec,ele);
      ele   = NULL;
    }
  }

  if( lattice.element.empty() )
  {
    cout<<"Error! \"lattice.txt\" has no effective element.\nexit."<<endl;
    exit(0);
  }
}

int Initial::InitMesh(Mesh &mesh)
{
  mesh.Initial(numofGrid,particleNumber);
}

int Initial::InitMethodMP(MethodMP &MP)
{
  MP.timeStep      =    1.0/frequency/stepPerCycle;
  MP.stepMax       =    maxStepNumber;
  MP.spaceChargeFlag=   spaceChargeFlag;
  MP.pusherType    =    pusher;
}

