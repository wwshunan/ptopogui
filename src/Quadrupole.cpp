#include "Quadrupole.h"

void Quadrupole::GetField(double time,Particle &particle)
{
  double bx = gradient * particle.xyz[2];
  double by = gradient * particle.xyz[0];
  particle.externalElecField = { 0, 0, 0};
  particle.externalMegnField = {bx,by, 0};
}

void Quadrupole::GetMatrix(Particle &)
{

}

void Quadrupole::SetParameter(double posit, const vector<string> & param)
{
  if(param.size()<5)
  {
    cout<<"Error! parameter not enough in element : \n"<<endl;
    for(int i = 0;i<param.size();++i)
    {
      cout<<param.at(i)<<"\t";
    }
    cout<<endl;
    return;
  }
  SetBasicParameter(posit,param);
  gradient =    stod( param.at(4) );
}

