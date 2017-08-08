#include <cmath>
#include <iostream>

#include "Beam.h"
#include "MyFunc.h"
#include "Global.h"

void Beam::SetField()
{
  for(unsigned int i=0; i < particleNumber;++i)
  {
    particle[i].GetTotalField();
    if(0&&i<10&&particle[i].totalElecField[2]>1e-8)
    {
      cout<<i<<"  "<<particle[i].xyz[4]<<"  "<<particle[i].totalElecField[2]<<endl;
      getchar();
    }
  }
}
void Beam::SetMatrix()
{
  for(unsigned int i=0; i < particleNumber; ++i)
  {
    particle[i].GetMatrix();
  }
}

void Beam::CaculateEmittance()
{
  vector<double> total(6,0.0),sigma(6,0),sigmaxdx(3,0),emit(3);
  particleLiveNumber	=0;
  eGammaTotal		=0;
  eBetaGammaTotal	=0;
  phiTotal		=0;
  eGammaSigma		=0;
  eBetaGammaSigma	=0;
  phiSigma		=0;
  PhiGamma		=0;
  PhiBetaGamma		=0;
  for(int i=0;i<particleNumber;i++)
  {
    if(particle[i].lossFlag)
    {
      continue;
    }
    eBeta [i]    = particle[i].xyz[5]/C_light;
    eGamma[i]	 = 1.0/sqrt(  1-pow(eBeta[i],2)  );
    eBetaGamma[i]= eBeta[i]*eGamma[i];
  }

  for(int i=0;i<particleNumber;i++)
  {
    if(particle[i].lossFlag)
    {
      continue;
    }
    for(int j=0;j<6;++j)
    {
      total[j]+=particle[i].xyz[j];
    }
    eGammaTotal		+=eGamma[i];
    eBetaGammaTotal	+=eBetaGamma[i];
    ++particleLiveNumber;
  }

  eBetaTotal	= total[5]/C_light;

  if(particleLiveNumber==0) 
  {
    cout<<"No particle LIVE, send in caculate_emittance"<<endl;
    return;
  }
  for(int i=0;i<6;++i)
  {
    average[i]          =       total[i]/particleLiveNumber;
  }
  eBetaAverage          =       eBetaTotal	/particleLiveNumber;
  eGammaAverage         =       eGammaTotal	/particleLiveNumber;
  eBetaGammaAverage     =       eBetaGammaTotal	/particleLiveNumber;

  dwwmax=0;
  dppmax=0;
  dbbmax=0;

  for(int i=0;i<particleNumber;i++)
  {
    if(particle[i].lossFlag)
    {
      continue;
    }
    for(int j=0;j<6;j=j+2)
    {
      sigma[j]		+= pow( particle[i].xyz[j]-average[j]    	                ,2);
      sigma[j+1]	+= pow((particle[i].xyz[j+1]-average[j+1])/particle[i].xyz[5]    ,2);
    }
    for(int j=0;j<3;++j)
    {
      sigmaxdx[j]	+= (particle[i].xyz[2*j]-average[2*j])	*	(particle[i].xyz[2*j+1]-average[2*j+1])	/	particle[i].xyz[5];
    }
    eGammaSigma		+= pow( eGamma[i]-eGammaAverage	,2);
    PhiGamma		+= (eGamma[i]-eGammaAverage)	*	(particle[i].xyz[4]  -average[4]);
    eBetaGammaSigma	+= pow( eBetaGamma[i]-eBetaGammaAverage	,2);
    PhiBetaGamma	+= (eBetaGamma[i]-eBetaGammaAverage)*	(particle[i].xyz[4]  -average[4]);	
    if(abs(eGamma[i]-eGammaAverage)/(eGammaAverage-1)>dwwmax) 
    {
      dwwmax=abs(eGamma[i]-eGammaAverage)/(eGammaAverage-1);
    }
    if(abs(eBetaGamma[i]-eBetaGammaAverage)/(eBetaGammaAverage)>dppmax) 
    {
      dppmax=abs(eBetaGamma[i]-eBetaGammaAverage)/(eBetaGammaAverage);
    }
    if(abs(eBeta[i]-eBetaAverage)/(eBetaAverage)>dbbmax) 
    {
      dbbmax=abs(eBeta[i]-eBetaAverage)/(eBetaAverage);
    }
  }
  sigmaz	=	eGammaSigma	/ pow(eGammaAverage-1	,2)/particleLiveNumber;
  eGammaSigma	=	eGammaSigma	/ pow(eGammaAverage	,2);
  eBetaGammaSigma=	eBetaGammaSigma	/ pow(eBetaGammaAverage	,2);
  PhiGamma	=	PhiGamma   	/    (eGammaAverage	)	*   (1/average[5]*frq*360  );
  PhiBetaGamma	=	PhiBetaGamma	/    (eBetaGammaAverage)	*   (1/average[5]*frq*360  );
  phiSigma	=	sigma[4]   					*pow(1/average[5]*frq*360,2);

  for(int j=0;j<6;++j)
  {
    sigma[j]	/=	particleLiveNumber;
  }
  for(int j=0;j<3;++j)
  {
    sigmaxdx[j]	/=	particleLiveNumber;
  }
  phiSigma	 /=particleLiveNumber;
  eGammaSigma	 /=particleLiveNumber;
  PhiGamma	 /=particleLiveNumber;
  eBetaGammaSigma/=particleLiveNumber;
  PhiBetaGamma	 /=particleLiveNumber;

  for(int i=0;i<3;++i)
  {
    emit[i]=sqrt(sigma[2*i]*sigma[2*i+1]-sigmaxdx[i]*sigmaxdx[i]);
  }
  //x
  x_sigma	=sigma[0];
  dx_sigma	=sigma[1];
  xdx_sigma	=sigmaxdx[0];
  emittancex	=emit[0];

  //y
  y_sigma	=sigma[2];
  dy_sigma	=sigma[3];
  ydy_sigma	=sigmaxdx[1];
  emittancey	=emit[1];

  //Z
  z_sigma	=phiSigma;
  sigmadz	=sigma[5];
  int emitZFlag=1;
  if(emitZFlag=1)       //phi dp space 
  {
    dz_sigma	=eBetaGammaSigma;
    zdz_sigma	=PhiBetaGamma;
    emittancez	=sqrt(z_sigma*dz_sigma-zdz_sigma*zdz_sigma);
  }
  else                  //phi dw space 
  {
    dz_sigma	=eGammaSigma;
    zdz_sigma	=PhiGamma;
    emittancez	=sqrt(z_sigma*dz_sigma-zdz_sigma*zdz_sigma);
  }
  TBetax	=x_sigma/emittancex;
  TBetay	=y_sigma/emittancey;
  TBetaz	=z_sigma/emittancez;
  TGammax	=dx_sigma/emittancex;
  TGammay	=dy_sigma/emittancey;
  TGammaz	=dz_sigma/emittancez;
  if(TBetax*TGammax>1)
  {
    TAlphax=(xdx_sigma<0?1:-1)*sqrt(TBetax*TGammax-1);
  }
  else
  {
    TAlphax=0;
  }
  if(TBetay*TGammay>1)
  {
    TAlphay=(ydy_sigma<0?1:-1)*sqrt(TBetay*TGammay-1);
  }
  else
  {
    TAlphay=0;
  }
  if(TBetaz*TGammaz>1)
  {
    TAlphaz=(zdz_sigma<0?1:-1)*sqrt(TBetaz*TGammaz-1);
  }
  else
  {
    TAlphaz=0;
  }
  ParaTransfer.push_back({
      average[4],                             //beam position Z       (m)
      (eGammaAverage-1)*BaseMassInMeV,        //Kinetic               (MeV)
      sqrt(x_sigma),                          //rms size in X         (m)
      sqrt(y_sigma),                          //rms size in Y         (m)
      sqrt(z_sigma),	                      //rms size in phi       (deg)
      sqrt(sigmaz),                           //sigma_dw
      emittancex*eBetaAverage*eGammaAverage,          //emit. nor. x  (m*rad)
      emittancey*eBetaAverage*eGammaAverage,          //emit. nor. y  (m*rad)
      emittancez/360/frq*1e9*BaseMassInMeV*1e3,       //emit. nor. z  (keV*ns)
      TBetax,
      TAlphax,
      TBetay,
      TAlphay,
      TBetaz,
      TAlphaz,
      particleLiveNumber,
      dppmax,
      dwwmax,
      dbbmax
      });
}

void Beam::CaculateSigma()
{
  vector<double> total(6);
  int particleLiveNumber=0;
  particleNumber=particle.size();
  for(int i=0;i < particleNumber;i++)
  {
    if(particle[i].lossFlag)
    {
      continue;
    }
    for(int j=0;j<6; j=j+2)
    {
      total[j]+=particle[i].xyz[j];
    }
    ++particleLiveNumber;
  }

  for(int i = 0 ; i < 6 ; i=i+2)
  {
    average[i] = total[i]/particleLiveNumber;
  }

  sigma=vector<double>(6,0);
  for(int i=0;i<particleNumber;i++)
  {
    if(particle[i].lossFlag)
    {
      continue;
    }
    for(int j = 0 ; j<6 ;j=j+2)
    {
      sigma[j]   += pow( particle[i].xyz[j]   - average[j],2);
    }
  }

  for(int i = 0 ; i < 6 ; i=i+2)
  {
    sigma[i] /= particleLiveNumber;
    sigma[i] =  sqrt(sigma[i]);
  }
}

void Beam::Print(ostream &par)
{
  PrintV1(par,ParaTransfer.back());
}


