#include "Drift.h"

void Drift::GetField(double time,Particle & particle)
{
  particle.externalElecField = {0,0,0};
  particle.externalMegnField = {0,0,0};
}

void Drift::GetMatrix(Particle &)
{

}

void Drift::SetParameter(double posit, const vector<string> & param)
{  
  if(param.size()<4)
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
}
