#include <iostream>
#include <fstream>
#include <QMutexLocker>

#include "MethodMP.h"
#include "PIC.h"

#include "Pusher.h"
#include "LeapFrog.h"
//#include "RK4.h"

using std::cout;
using std::endl;

MethodMP::~MethodMP()
{}
MethodMP::MethodMP()
{}

void MethodMP::Push(Lattice &lattice,Mesh &mesh,Beam &beam, bool& paused, QWaitCondition& toResume, QMutex& mutex)
{

  PIC pic(mesh,beam);

  Pusher *pusher;
  if(pusherType=="leapfrog")
  {
    pusher = new LeapFrog;
  }
  else if(pusherType == "rk4")
  {
    //pusher = new RK4;
  }
  ofstream fout("output.dat");

  for(int i = 0; i<stepMax; ++i)
  {
      {
          QMutexLocker locker(&mutex);
          if (paused) {
              toResume.wait(&mutex);
          }
      }
    beam.         CaculateEmittance     (               );
    beam.         Print                 (fout           );
    
    if(spaceChargeFlag==1)
    {
      pic.        GetInternalFiled      (mesh,  beam    );     //InternalField.getfield();
    }
    
    lattice.      GetExternalField      (timeNow,  beam );    //ExternalField.getfield();
    beam.         SetField              (               );
    pusher->      Update                (timeStep ,beam );                   //Pusher.update();
    lattice.      LostCount             (beam           );
    timeNow     +=timeStep;
    
    cout<<beam.average[4]<<"/"<<lattice.positionBack.back()<<"\t "<<beam.particleLiveNumber<<"/"<<beam.particleNumber<<endl;
    if(beam.average[4]>lattice.positionBack.back())   //beam are out of lattice
    {
      break;
    }
    
    if(beam.particleLiveNumber==0)
    {
      break;
    }
  }

  delete pusher;

}
