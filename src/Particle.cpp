#include <iostream>
#include "Particle.h"
#include "Global.h"

Particle::Particle()
{
  xyz.                  resize(6);
  externalElecField.    resize(3);
  externalMegnField.    resize(3);
  internalElecField.    resize(3);
  internalMegnField.    resize(3);
  totalElecField.       resize(3);
  totalMegnField.       resize(3);
}

void Particle::GetTotalField()       // to obtain the total field
{
  double factor;
  double gamma;
  for(int i = 0; i<3 ;++i)
  {
    gamma=1/sqrt(1-xyz[5]*xyz[5]/(C_light*C_light));
    factor=charge/(gamma*mass);
    totalElecField[i] = (externalElecField[i] + internalElecField[i]) * factor; //the field had mulitplied Q and divided by M and gamma already!!
    totalMegnField[i] = (externalMegnField[i] + internalMegnField[i]) * factor;
  }
}

void Particle::GetMatrix()         // to obtain the transfer matrix for each particle
{
//   particleTranferMap.      resize(6);
//   particleTranferMap.cols() = 6;
   
   
}
