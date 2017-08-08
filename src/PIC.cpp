#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

#include "MyFunc.h"
#include "PIC.h"

using namespace std;

PIC::PIC()
{
}
PIC::PIC(Mesh &mesh,Beam &beam)
{
  Initial(mesh,beam);
}
PIC::~PIC()
{
  fftw_free(in);
  fftw_free(out);

  fftw_free(in_xy);
  fftw_free(out_xy);

  fftw_free(in_z);
  fftw_free(out_z);

  fftw_free(outf); 
  fftw_free(outf_z);

  fftw_destroy_plan(rhoGridToFourier_XY);
  fftw_destroy_plan(phiFourierToGrid_XY);

  fftw_destroy_plan(rhoGridToFourier_Z);
  fftw_destroy_plan(phiFourierToGrid_Z);
}

int PIC::Initial(Mesh &mesh,Beam &beam)
{
  cout<<"PIC Initialing..."<<endl;
  numofgridx = mesh.numberOfGrid[0];
  numofgridy = mesh.numberOfGrid[1];
  numofgridz = mesh.numberOfGrid[2];

  weighOfGrid       =  v2d(beam.particle.size(), v1d(8));   //store assigned volume for each particle in certain mesh
  particleOutOfMesh =  v1i(beam.particle.size(), 0);

  in  	= (double*)             fftw_malloc(sizeof(double)      * numofgridx * numofgridy * numofgridz);
  out 	= (double*)             fftw_malloc(sizeof(double)      * numofgridx * numofgridy * numofgridz);
  outf 	= (double*)             fftw_malloc(sizeof(double)      * numofgridx * numofgridy * numofgridz);
  in_xy = (double*)             fftw_malloc(sizeof(double)      * numofgridx * numofgridy * numofgridz);
  out_xy= (double*)             fftw_malloc(sizeof(double)      * numofgridx * numofgridy * numofgridz);
  in_z  = (fftw_complex*)       fftw_malloc(sizeof(fftw_complex)* numofgridx * numofgridy * numofgridz);
  out_z = (fftw_complex*)       fftw_malloc(sizeof(fftw_complex)* numofgridx * numofgridy * numofgridz);
  outf_z= (fftw_complex*)       fftw_malloc(sizeof(fftw_complex)* numofgridx * numofgridy * numofgridz);


  // FFTW in z direction is complex, set the image part of in_z to 0;


  for(int i=0;i<numofgridx;++i)
  {
    for(int j=0;j<numofgridy;++j)
    {
      for(int k=0;k<numofgridz;++k)
      {
        in_z[i * numofgridy * numofgridz + j * numofgridz + k][1]=0.0;
      }
    }
  }

  //1
  fftw_plan_with_nthreads(omp_get_max_threads());
  int n_xy[]={numofgridx,numofgridy};

  rhoGridToFourier_XY=fftw_plan_many_r2r(2, n_xy, numofgridz,

      in_xy  ,n_xy,
      numofgridz, 1,
      out_xy ,n_xy,
      numofgridz, 1,
      kind_xy_forward, FFTW_MEASURE);
  //2
  fftw_plan_with_nthreads(omp_get_max_threads());
  int n_z[]={numofgridz};
  rhoGridToFourier_Z=fftw_plan_many_dft(1, n_z, numofgridx*numofgridy,
      in_z , n_z ,
      1,numofgridz,
      out_z, n_z ,
      1,numofgridz,
      FFTW_FORWARD, FFTW_MEASURE);
  //3
  fftw_plan_with_nthreads(omp_get_max_threads());
  phiFourierToGrid_Z=fftw_plan_many_dft(1, n_z, numofgridx*numofgridy,
      out_z  , n_z ,
      1,numofgridz,
      outf_z, n_z ,
      1,numofgridz,
      FFTW_BACKWARD, FFTW_MEASURE);
  //4
  fftw_plan_with_nthreads(omp_get_max_threads());
  phiFourierToGrid_XY=fftw_plan_many_r2r(2, n_xy, numofgridz,
      out_xy,n_xy,
      numofgridz, 1,
      in_xy,n_xy ,
      numofgridz, 1,
      kind_xy_backward, FFTW_MEASURE);
  return 1;
}

int PIC::Weight(Mesh &mesh,Beam &beam)
{
    if(beam.particle.size()==0)
    {
      cout<<"No particle exist!"<<endl;
      return -1;
    }


  for(int i = 0; i < mesh.numberOfGrid[0]; ++i)
  {
    for(int j = 0; j < mesh.numberOfGrid[1]; ++j)
    {
      for(int k = 0; k < mesh.numberOfGrid[2]; ++k)
      {
        mesh.rho[i][j][k]=0;
      }
    }
  }
  
  //caculate the step
  beam.CaculateSigma();
  stepx=sqrt(beam.sigma[0])*2*3.5/(numofgridx);
  stepy=sqrt(beam.sigma[2])*2*3.5/(numofgridy);
  if(0)//&&.name=="rfq")
  {
    //stepz=  beam.average[4]/ MyLattice.ELE[MyLattice.getEleNum(beam.average[4])].p[4]/numofgridz;
  }
  else
  {
    stepz=sqrt(beam.sigma[4])*2*3.5/(numofgridz);
  }

  for(int i=0;i<mesh.numberOfGrid[0];i++)
  {
    mesh.meshx[i]=beam.average[0]+stepx*(i - mesh.numberOfGrid[0]/2.0+0.5);
  }
  for(int i=0;i<mesh.numberOfGrid[1];++i)
  {
    mesh.meshy[i]=beam.average[0]+stepy*(i - mesh.numberOfGrid[0]/2.0+0.5);
  }
  for(int i=0;i<mesh.numberOfGrid[2];++i)
  {
    mesh.meshz[i]=beam.average[0]+stepz*(i  -mesh.numberOfGrid[0]/2.0+0.5);
  }
  vt=stepx*stepy*stepz;
        



  int idx,idy,idz;

  for(int i=0;i<beam.particle.size();i++)
  {

    if(beam.particle[i].lossFlag) 
    {
      continue;
    }


    mesh.countx[i]=floor((beam.particle[i].xyz[0]-mesh.meshx[0])/stepx);
    mesh.county[i]=floor((beam.particle[i].xyz[2]-mesh.meshy[0])/stepy);
    mesh.countz[i]=floor((beam.particle[i].xyz[4]-mesh.meshz[0])/stepz);

    if(   mesh.countx[i]>=mesh.numberOfGrid[0]-1         //Take a notice about FFT and FFT_sin in the mannul of FFTW lib.       
        ||mesh.county[i]>=mesh.numberOfGrid[1]-1           
        ||mesh.countz[i]>=mesh.numberOfGrid[2]          
        ||mesh.countx[i]<0                              
        ||mesh.county[i]<0
        ||mesh.countz[i]<0)
    {
      particleOutOfMesh[i]=1;              
      for(int j=0;j<8;++j)
      {

        weighOfGrid[i][j]=  0;

      }
    }
    else
    {
      particleOutOfMesh[i]=0;

      for(int j=0;j<8;++j)
      {
        if(mesh.countz[i]==numofgridz-1)
        {
           idz=(j <=3)     ? -mesh.countz[i] : 0 ;
        }
        else
        {
            idz=(j <=3) 	? 1 : 0;
        }

        weighOfGrid[i][j]=  
        abs( beam.particle[i].xyz[0] - mesh.meshx[mesh.countx[i]+ ((j%2==0)	? 1 : 0) ]) * 
        abs( beam.particle[i].xyz[2] - mesh.meshy[mesh.county[i]+ ((j%4< 2) 	? 1 : 0) ]) *
        abs( beam.particle[i].xyz[4] - mesh.meshz[mesh.countz[i]+ idz ])
        /vt;
      }
    }
  }

  particleInMeshNumber=0;
  for(int i=0;i<beam.particle.size();++i)
  {
    if(beam.particle[i].lossFlag or particleOutOfMesh[i]) continue;
    ++particleInMeshNumber;
    mesh.rho[mesh.countx[i]  ][mesh.county[i]  ][mesh.countz[i]]      += weighOfGrid[i][0] * beam.particle[i].charge;
    mesh.rho[mesh.countx[i]+1][mesh.county[i]  ][mesh.countz[i]]      += weighOfGrid[i][1] * beam.particle[i].charge;
    mesh.rho[mesh.countx[i]  ][mesh.county[i]+1][mesh.countz[i]]      += weighOfGrid[i][2] * beam.particle[i].charge;
    mesh.rho[mesh.countx[i]+1][mesh.county[i]+1][mesh.countz[i]]      += weighOfGrid[i][3] * beam.particle[i].charge;
    if(mesh.countz[i]==numofgridz-1)
    {
      mesh.rho[mesh.countx[i]  ][mesh.county[i]  ][0]   += weighOfGrid[i][4]*beam.particle[i].charge;
      mesh.rho[mesh.countx[i]+1][mesh.county[i]  ][0]   += weighOfGrid[i][5]*beam.particle[i].charge;
      mesh.rho[mesh.countx[i]  ][mesh.county[i]+1][0]   += weighOfGrid[i][6]*beam.particle[i].charge;
      mesh.rho[mesh.countx[i]+1][mesh.county[i]+1][0]   += weighOfGrid[i][7]*beam.particle[i].charge;
    }
    else
    {
      mesh.rho[mesh.countx[i]  ][mesh.county[i]  ][mesh.countz[i]+1]    += weighOfGrid[i][4]*beam.particle[i].charge;
      mesh.rho[mesh.countx[i]+1][mesh.county[i]  ][mesh.countz[i]+1]    += weighOfGrid[i][5]*beam.particle[i].charge;
      mesh.rho[mesh.countx[i]  ][mesh.county[i]+1][mesh.countz[i]+1]    += weighOfGrid[i][6]*beam.particle[i].charge;
      mesh.rho[mesh.countx[i]+1][mesh.county[i]+1][mesh.countz[i]+1]    += weighOfGrid[i][7]*beam.particle[i].charge;
    }
  }
  return 1;
}
//in x and y diretion, we do not deal with boundary charge. In longitudinal direction, we add the one external slice just out of mesh and the first
//slice together.


int PIC::FFT(Mesh &mesh)
{
  //forward Fourier
  //#pragma omp for
  for(int i=0;i<numofgridx;++i)
  {
    for(int j=0;j<numofgridy;++j)
    {
      for(int k=0;k<numofgridz;++k)
      {
        in_xy[i*numofgridy*numofgridz+j*numofgridz+k]=mesh.rho[i][j][k]/stepx/stepy/stepz;

      }
    }
  }

  //#pragma omp barrier
  //#pragma omp single 
  fftw_execute(rhoGridToFourier_XY);
  //#pragma omp barrier
  int coun365;
  //#pragma omp for
  for(int i=0;i<numofgridx;++i)
  {
    for(int j=0;j<numofgridy;++j)
    {
      for(int k=0;k<numofgridz;++k)
      {
        coun365=i*numofgridy*numofgridz+j*numofgridz+k;
        in_z[coun365][0]=out_xy[coun365];
      }
    }
  }

  //#pragma omp barrier
  //#pragma omp single 
  fftw_execute(rhoGridToFourier_Z);
  //#pragma omp barrier

  //devide by K
  
  double K_rho2phi=0,knx=0,kny=0,knz=0;
  int coun445;
  //#pragma omp for
  for(int i=0;i<numofgridx;++i)
  {
    for(int j=0;j<numofgridy;++j)
    {
      for(int k=0;k<numofgridz;++k)
      {
        if(i==0&&j==0&&k==0)
        {
          continue;
        }
        knx=M_PI/2*(i+1)/(numofgridx+1);
        kny=M_PI/2*(j+1)/(numofgridy+1);
        knz=M_PI  *(k)/(numofgridz);            // chech the formular used in FFTW mannul in function FFT,  
                                                // The SK function is uniquely decided/////
        K_rho2phi=   pow(2*sin(knx)/stepx,2)
                    +pow(2*sin(kny)/stepy,2)
                    +pow(2*sin(knz)/stepz,2);
        
        coun445=i*numofgridy*numofgridz+j*numofgridz+k;
        out_z[coun445][0]/=K_rho2phi*Epsilon;
        out_z[coun445][1]/=K_rho2phi*Epsilon;
      }
    }
  }
  //#pragma omp single
  if(1)
  {
    out_z[0][0]=0;
    out_z[0][1]=0;
  }
  //backward Fourier

  //#pragma omp barrier
  //#pragma omp single 
  fftw_execute(phiFourierToGrid_Z);
  //#pragma omp barrier

  //#pragma omp for
  for(int i=0;i<numofgridx;++i)
  {
    for(int j=0;j<numofgridy;++j)
    {
      for(int k=0;k<numofgridz;++k)
      {
            coun365=i*numofgridy*numofgridz+j*numofgridz+k;
            out_xy[coun365]=outf_z[coun365][0];
      }
    }
  }

  //#pragma omp barrier
  //#pragma omp single 
  fftw_execute(phiFourierToGrid_XY);
  //#pragma omp barrier


  //#pragma omp for
  for(int i=0;i<numofgridx;i++)
  {
    for(int j=0;j<numofgridy;j++)
    {
      for(int k=0;k<numofgridz;++k)
      {
        mesh.phi[i][j][k]=in_xy[i*numofgridy*numofgridz+j*numofgridz+k]/(4*(numofgridx+1)*(numofgridy+1)*(numofgridz));
        //check the fftw normalized rules
      }
    }
  }

  //Diferentiate to get the efield
  //#pragma omp for
  for(int i=0;i<numofgridx;++i)
  {
    for(int j=0;j<numofgridy;++j)
    {
      for(int k=0;k<numofgridz;++k)
      {
        if(i==0)
        {
           mesh.ex[i][j][k]        =-(mesh.phi[i+1][j][k]  -0)/stepx/2;                  //unit:V/m;
        }
        else if(i==numofgridx-1)
        {
           mesh.ex[i][j][k]        =-(0  -mesh.phi[i-1][j][k])/stepx/2;                  //unit:V/m;
        }
        else
        {
           mesh.ex[i][j][k]        =-(mesh.phi[i+1][j][k]  -mesh.phi[i-1][j][k])/stepx/2;
        }
        
        if(j==0)
        {
           mesh.ey[i][j][k]        =-(mesh.phi[i][j+1][k]  -0)/stepy/2;
        }
        else if(j==numofgridy-1)
        {
           mesh.ey[i][j][k]        =-(0  -mesh.phi[i][j-1][k])/stepy/2;
        }
        else
        {
           mesh.ey[i][j][k]        =-(mesh.phi[i][j+1][k]  -mesh.phi[i][j-1][k])/stepy/2;
        }
        
        if(k==0)
        {
          mesh.ez[i][j][k]      =-(mesh.phi[i][j][k+1]  -mesh.phi[i][j][numofgridz-1])/stepz/2;
        }
        else if(k==numofgridz-1)
        {
          mesh.ez[i][j][k]      =-(mesh.phi[i][j][0]    -mesh.phi[i][j][k-1])/stepz/2;
        }
        else
        {
          mesh.ez[i][j][k]      =-(mesh.phi[i][j][k+1]  -mesh.phi[i][j][k-1])/stepz/2;
        }
      }
    }
  }
  return 0;
}

int PIC::Allocate(const Mesh &mesh, Beam &beam)
{
  double e1=0,e2=0,e3=0,b1=0,b2=0,b3=0;
  double gamma,beta;

  for(int i=0;i<beam.particle.size();++i)
  {
    if(beam.particle[i].lossFlag)
    {
      continue;
    }
    if(!particleOutOfMesh[i])
    {

      e1  =   mesh.ex[mesh.countx[i]  ][mesh.county[i]  ][mesh.countz[i]  ]     * weighOfGrid[i][0]
	+     mesh.ex[mesh.countx[i]+1][mesh.county[i]  ][mesh.countz[i]  ]     * weighOfGrid[i][1]
	+     mesh.ex[mesh.countx[i]  ][mesh.county[i]+1][mesh.countz[i]  ]     * weighOfGrid[i][2]
	+     mesh.ex[mesh.countx[i]+1][mesh.county[i]+1][mesh.countz[i]  ]     * weighOfGrid[i][3]
	+     mesh.ex[mesh.countx[i]  ][mesh.county[i]  ][mesh.countz[i]+1]     * weighOfGrid[i][4]
	+     mesh.ex[mesh.countx[i]+1][mesh.county[i]  ][mesh.countz[i]+1]    	* weighOfGrid[i][5]
	+     mesh.ex[mesh.countx[i]  ][mesh.county[i]+1][mesh.countz[i]+1]    	* weighOfGrid[i][6]
	+     mesh.ex[mesh.countx[i]+1][mesh.county[i]+1][mesh.countz[i]+1]     * weighOfGrid[i][7];
      e2  =   mesh.ey[mesh.countx[i]  ][mesh.county[i]  ][mesh.countz[i]  ]     * weighOfGrid[i][0]
	+     mesh.ey[mesh.countx[i]+1][mesh.county[i]  ][mesh.countz[i]  ]    	* weighOfGrid[i][1]
	+     mesh.ey[mesh.countx[i]  ][mesh.county[i]+1][mesh.countz[i]  ]    	* weighOfGrid[i][2]
	+     mesh.ey[mesh.countx[i]+1][mesh.county[i]+1][mesh.countz[i]  ]     * weighOfGrid[i][3]
	+     mesh.ey[mesh.countx[i]  ][mesh.county[i]  ][mesh.countz[i]+1]     * weighOfGrid[i][4]
	+     mesh.ey[mesh.countx[i]+1][mesh.county[i]  ][mesh.countz[i]+1]     * weighOfGrid[i][5]
	+     mesh.ey[mesh.countx[i]  ][mesh.county[i]+1][mesh.countz[i]+1]     * weighOfGrid[i][6]
	+     mesh.ey[mesh.countx[i]+1][mesh.county[i]+1][mesh.countz[i]+1]     * weighOfGrid[i][7];
      e3  =   mesh.ez[mesh.countx[i]  ][mesh.county[i]  ][mesh.countz[i]  ]     * weighOfGrid[i][0]
	+     mesh.ez[mesh.countx[i]+1][mesh.county[i]  ][mesh.countz[i]  ]    	* weighOfGrid[i][1]
	+     mesh.ez[mesh.countx[i]]  [mesh.county[i]+1][mesh.countz[i]  ]    	* weighOfGrid[i][2]
	+     mesh.ez[mesh.countx[i]+1][mesh.county[i]+1][mesh.countz[i]  ]     * weighOfGrid[i][3]
	+     mesh.ez[mesh.countx[i]  ][mesh.county[i]  ][mesh.countz[i]+1]     * weighOfGrid[i][4]
	+     mesh.ez[mesh.countx[i]+1][mesh.county[i]  ][mesh.countz[i]+1]     * weighOfGrid[i][5]
	+     mesh.ez[mesh.countx[i]  ][mesh.county[i]+1][mesh.countz[i]+1]     * weighOfGrid[i][6]
	+     mesh.ez[mesh.countx[i]+1][mesh.county[i]+1][mesh.countz[i]+1]     * weighOfGrid[i][7];


      //Lorentz Transform verir
      beta      =beam.particle[i].xyz[4]/C_light;
      gamma     =1.0/sqrt(1-beta*beta);
      e1        =e1/C_light;
      e2        =e2/C_light;
      e3        =e3/C_light;
      beam.particle[i].internalElecField[0]= C_light    *gamma*(e1+beta*b2);
      beam.particle[i].internalElecField[1]= C_light    *gamma*(e2-beta*b1);
      beam.particle[i].internalElecField[2]= C_light    *e3;
      beam.particle[i].internalMegnField[0]=            gamma*(b1-beta*e2);
      beam.particle[i].internalMegnField[1]=            gamma*(b2+beta*e1);
      beam.particle[i].internalMegnField[2]=            b3;
    }
    else
    {
      beam.particle[i].internalElecField[0]=0;
      beam.particle[i].internalElecField[1]=0;
      beam.particle[i].internalElecField[2]=0;
      beam.particle[i].internalMegnField[0]=0;
      beam.particle[i].internalMegnField[1]=0;
      beam.particle[i].internalMegnField[2]=0;
    }
  }
}

