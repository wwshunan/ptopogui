#include"LinearMT.h"
#include<vector>
#include<iostream>

using namespace Eigen;
using namespace std;

void LinearMT::Update(Beam &beam,Lattice &lattice,double stepinElement)
{
/*    int particleNumber = beam.particle.size();
    
    VectorXd particleInfo(6);
    MatrixXd transferMatrix(6,6);
      
    for(int i=0;i<particleNumber;++i)
    {
        
        if (beam.particle[i].lossFlag)
        {
            continue;
        }
        
       for(int j=0;j<6;++j)
       {
            particleInfo(j) = beam.particle[i].xyz[j];
       }
       
        particleInfo  =   beam.particle[i].particleTranferMap * particleInfo;
        
        for(int j; j<6;++j)
        {
            beam.particle[i].xyz[j] = particleInfo(j);
        }
    
    }*/
}

