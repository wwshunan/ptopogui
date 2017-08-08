#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio> 
#include <cstdlib>
#include <cmath>
#include <complex>
#include <Eigen/Dense>

#include "Distribution.h"
#include "MyFunc.h"
#include "FukushimaLambertW.h"
using namespace std;

void KV2DTwiss(const vector<double> &twiss,vector<vector<double> > &xy)
{
  
  //input vector1:
  //    {Emitx,     Betax,  Alphax, 
  //     Emity,     Betay,  Alphay}
  //Input vector2:
  //    Matrix of N*6 , N is the size of vector and means the number of particle
  //    Each particle takes a vector in form {x, px, y, py ,z, pz}
  vector<double> sigma=TwissToSigma2D(twiss);
//  cout<<"sigmaX  "<<sigma[0]<<endl;
//  cout<<"sigmaDX "<<sigma[1]<<endl;
  //TODO: compare sigmax and ax,
  //              sigmadx and ax'
  KV2DSigma(sigma,xy);
}

void KV2DSigma(const vector<double> &param,vector<vector<double> > &xy)
{
  //input vector1:
  //    {sigmaX2,    sigmaPX2,        sigmaXPX, 
  //     sigmaY2,    sigmaPY2,        sigmaYPY}
  //Input vector2:
  //    Matrix of N*6 , N is the size of vector and means the number of particle
  //    Each particle takes a vector in form {x, px, y, py ,z, pz}
  vector<double> axial=SigmaToAxial2D(param);
  KV2DAxial(axial,xy);
}

void KV2DAxial(const vector<double> &param,vector<vector<double> > &xy)
{
  //input vector1:
  //    {emittence_X,       semiaxis_X1,    semiaxis_X2,    tilt_X,
  //     emittence_Y,       semiaxis_Y1,    semiaxis_Y2,    tilt_Y}
  //Input vector2:
  //    Matrix of N*6 , N is the size of vector and means the number of particle
  //    Each particle takes a vector in form {x, px, y, py ,z, pz}
  if(param.size()<8)    
  {
    cout<<"Axial input parameter error!"<<endl;
    return;
  }
  vector<double> paramRet=distribution_base1(param);
  double Factor=param.at(0);
  double G=0;
  for(auto num=xy.begin();num!=xy.end();++num)
  {
    //G=(double)rand() / RAND_MAX;
    paramRet.back()=Factor;
    distribution_base2(paramRet,*num);
  }
}

void PB2DTwiss(const vector<double> &twiss,vector<vector<double> > &xy)
{  
  //input vector1:
  //    {Emitx,     Betax,  Alphax, 
  //     Emity,     Betay,  Alphay}
  //Input vector2:
  //    Matrix of N*6 , N is the size of vector and means the number of particle
  //    Each particle takes a vector in form {x, px, y, py ,z, pz}
  vector<double> sigma=TwissToSigma2D(twiss);
  PB2DSigma(sigma,xy);
}

void PB2DSigma(const vector<double> &param,vector<vector<double> > &xy)
{
  //input vector1:
  //    {sigmaX2,    sigmaPX2,        sigmaXPX, 
  //     sigmaY2,    sigmaPY2,        sigmaYPY}
  //Input vector2:
  //    Matrix of N*6 , N is the size of vector and means the number of particle
  //    Each particle takes a vector in form {x, px, y, py ,z, pz}
  vector<double> axial=SigmaToAxial2D(param);
  PB2DAxial(axial,xy);
}

void PB2DAxial(const vector<double> &param,vector<vector<double> > &xy)
{
  //input vector1:
  //    {emittence_X,       semiaxis_X1,    semiaxis_X2,    tilt_X,
  //     emittence_Y,       semiaxis_Y1,    semiaxis_Y2,    tilt_Y}
  //Input vector2:
  //    Matrix of N*6 , N is the size of vector and means the number of particle
  //    Each particle takes a vector in form {x, px, y, py ,z, pz}
  if(param.size()<8)    
  {
    cout<<"Axial input parameter error!"<<endl;
    return;
  }
  vector<double> paramRet=distribution_base1(param);
  double Factor=param.at(0)*2;
  double G=0;
  complex<double> temp2   =1.0 + complex<double>(0.0,1.0) * sqrt(3);
  complex<double> temp1   =1.0 - complex<double>(0.0,1.0) * sqrt(3);
  complex<double> temp3(0,0);
  for(auto num=xy.begin();num!=xy.end();++num)
  {
    G=(double)rand() / RAND_MAX;
    temp3=pow(1 - 2*G + 2.0*sqrt(complex<double>(-G + pow(G,2),0.0)),1.0/3);
    paramRet.back()=Factor*(0.5 + (temp1/(4.0*temp3)).real()  +  (temp2*temp3/4.0).real());
    distribution_base2(paramRet,*num);
  }
}

void WB2DTwiss(const vector<double> &twiss,vector<vector<double> > &xy)
{  
  //input vector1:
  //    {Emitx,     Betax,  Alphax, 
  //     Emity,     Betay,  Alphay}
  //Input vector2:
  //    Matrix of N*6 , N is the size of vector and means the number of particle
  //    Each particle takes a vector in form {x, px, y, py ,z, pz}
  vector<double> sigma=TwissToSigma2D(twiss);
  WB2DSigma(sigma,xy);
}

void WB2DSigma(const vector<double> &param,vector<vector<double> > &xy)
{
  //input vector1:
  //    {sigmaX2,    sigmaPX2,        sigmaXPX, 
  //     sigmaY2,    sigmaPY2,        sigmaYPY}
  //Input vector2:
  //    Matrix of N*6 , N is the size of vector and means the number of particle
  //    Each particle takes a vector in form {x, px, y, py ,z, pz}
  vector<double> axial=SigmaToAxial2D(param);
  WB2DAxial(axial,xy);
}

void WB2DAxial(const vector<double> &param,vector<vector<double> > &xy)
{
  //input vector1:
  //    {emittence_X,       semiaxis_X1,    semiaxis_X2,    tilt_X,
  //     emittence_Y,       semiaxis_Y1,    semiaxis_Y2,    tilt_Y}
  //Input vector2:
  //    Matrix of N*6 , N is the size of vector and means the number of particle
  //    Each particle takes a vector in form {x, px, y, py ,z, pz}
  if(param.size()<8)    
  {
    cout<<"Axial input parameter error!"<<endl;
    return;
  }
  vector<double> paramRet=distribution_base1(param);
  double Factor=param.at(0)/2*3;
  double G=0;
  for(auto num=xy.begin();num!=xy.end();++num)
  {
    G=(double)rand() / RAND_MAX;
    paramRet.back()=Factor*sqrt(G);
    distribution_base2(paramRet,*num);
  }
}

void GS2DTwiss(const vector<double> &twiss,vector<vector<double> > &xy)
{  
  //input vector1:
  //    {Emitx,     Betax,  Alphax, 
  //     Emity,     Betay,  Alphay}
  //Input vector2:
  //    Matrix of N*6 , N is the size of vector and means the number of particle
  //    Each particle takes a vector in form {x, px, y, py ,z, pz}
  vector<double> sigma=TwissToSigma2D(twiss);
  GS2DSigma(sigma,xy);
}

void GS2DSigma(const vector<double> &param,vector<vector<double> > &xy)
{
  //input vector1:
  //    {sigmaX2,    sigmaPX2,        sigmaXPX, 
  //     sigmaY2,    sigmaPY2,        sigmaYPY}
  //Input vector2:
  //    Matrix of N*6 , N is the size of vector and means the number of particle
  //    Each particle takes a vector in form {x, px, y, py ,z, pz}
  vector<double> axial=SigmaToAxial2D(param);
  GS2DAxial(axial,xy);
}

void GS2DAxial(const vector<double> &param,vector<vector<double> > &xy)
{
  //input vector1:
  //    {emittence_X,       semiaxis_X1,    semiaxis_X2,    tilt_X,
  //     emittence_Y,       semiaxis_Y1,    semiaxis_Y2,    tilt_Y}
  //Input vector2:
  //    Matrix of N*6 , N is the size of vector and means the number of particle
  //    Each particle takes a vector in form {x, px, y, py ,z, pz}
  if(param.size()<8)    
  {
    cout<<"Axial input parameter error!"<<endl;
    return;
  }
  vector<double> paramRet=distribution_base1(param);
  double Factor=param.at(0)/2;
  double G=0;
  for(auto num=xy.begin();num!=xy.end();++num)
  {
    G=(double)rand() / RAND_MAX;
    //paramRet.back()=abs(Factor*(-1-Lambert((G-1)/M_E/M_E)));
    paramRet.back()=abs(Factor*(-1-Fukushima::LambertW(-1,(G-1)/M_E)));
    distribution_base2(paramRet,*num);
    //cout<<G<<"  "<<Factor<<"  "<<paramRet.back()<<"  "<<(*num)[0]<<"  "<<(*num)[1]<<endl;
  }
}


void KV3DTwiss(const vector<double> &twiss,vector<vector<double> > &xy)
{
  //vector twiss:
  //Emitx, Betax, Alphax, 
  //Emity, Betay, Alphay, 
  //Emitz, Betaz, Alphaz	in (z,z') plane
  
  if(twiss.size()<9)    
  {
    cout<<"KV3DTwiss input parameter error!"<<endl;
    return;
  }
  KV2DTwiss(twiss,xy);
  
  vector<double> twissz(6);
  vector<vector<double> > z=xy;
  for(int i=0;i<6;++i)
  {
    if(i<3)
    {
      twissz[i]=twiss[i+6];
    }
    else
    {
      twissz[i]=twiss[i+3];
    }
  }
  
  KV2DTwiss(twissz,z);

  for(int i=0;i<xy.size();++i)
  {
    xy[i][4]=z[i][0];
    xy[i][5]=z[i][1];
  }
}

void GS3DSigma(const vector<double> &sigma,vector<vector<double> > &xy)
{
  vector<vector<double> > z=xy;
  //input vector sigma:
  //    {sigmaX2,    sigmaPX2,        sigmaXPX, 
  //     sigmaY2,    sigmaPY2,        sigmaYPY,
  //     sigmaZ2,    sigmaPZ2,        sigmaZPZ}
  
  if(sigma.size()<9)    
  {
    cout<<"GS3DSigma input parameter error!"<<endl;
    return;
  }
  GS2DSigma(sigma,xy);
  
  vector<double> sigmaz(6);

  for(int i=0;i<6;++i)
  {
    if(i<3)
    {
      sigmaz[i]=sigma[i+6];
    }
    else
    {
      sigmaz[i]=sigma[i+3];
    }
  }
  
  GS2DSigma(sigmaz,z);

  for(int i=0;i<xy.size();++i)
  {
    xy[i][4]=z[i][0];
    xy[i][5]=z[i][1];
  }
}

vector<double> TwissToSigma2D(const vector<double> &twiss)
{
  //input vector:
  //{Emitx,     Betax,  Alphax, 
  // Emity,     Betay,  Alphay}
  //output vector:
  //{sigmaX2,    sigmaPX,        sigmaXPX, 
  // sigmaY2,    sigmaPY,        sigmaYPY}
  if(twiss.size()<6)
  {
    cout<<"Error! twiss.size() < 6, from TwissToSigma2D in Distribution"<<endl;
    return {0};
  }
  double sigx   = twiss.at(1)   *       twiss.at(0)                     /4;
  double sigpx  = ( pow(twiss.at(2),2)+1 )/twiss.at(1)*twiss.at(0)      /4;
  double sigxpx = -twiss.at(2)*twiss.at(0)                              /4;
  double sigy   = twiss.at(4)   *       twiss.at(3)                     /4;
  double sigpy  = ( pow(twiss.at(5),2)+1 )/twiss.at(4)*twiss.at(3)      /4;
  double sigypy = -twiss.at(5)*twiss.at(3)                              /4;
  vector<double> temp={sigx,sigpx,sigxpx,sigy,sigpy,sigypy};
  return temp;
}

vector<double>  SigmaToAxial2D(const vector<double > &param)
{
  //input vector:
  //{sigmaX2,    sigmaPX,        sigmaXPX, 
  // sigmaY2,    sigmaPY,        sigmaYPY}
  //output vector:
  //{emittence_X,       semiaxis_X1,    semiaxis_X2,    tilt_X,
  // emittence_Y,       semiaxis_Y1,    semiaxis_Y2,    tilt_Y}
  
  double sig_x   =param[0];
  double sig_px  =param[1];
  double sig_xpx =param[2];
  double sig_y   =param[3];
  double sig_py  =param[4];
  double sig_ypy =param[5];
  
  if(sig_x*sig_px<=sig_xpx*sig_xpx||sig_y*sig_py<=sig_ypy*sig_ypy)
  {
    cout<<"ERROR!!!   @SigmaToAxial2D!"<<endl;
    return {0};
  }
  Eigen::MatrixXd CM = Eigen::MatrixXd::Zero(2,2);
  Eigen::VectorXd eivals;

  double x1=2*sig_xpx/sqrt(sig_px);
  double px1=2*sqrt(sig_px);
  double x2=2*sqrt(sig_x);
  double px2=2*sig_xpx/sqrt(sig_x);
  double Bx=-2*px2/px1/(x2*px1-x1*px2);
  double Cx=x2/px1/(x2*px1-x1*px2);
  double Ax=(1+px2*px2*Cx)/x2/x2;
  CM<<Ax,   Bx/2,
      Bx/2, Cx;
  eivals = CM.selfadjointView<Eigen::Lower>().eigenvalues();
  if(sig_x<sig_px)
  {
    double temp = eivals(0);
    eivals(0)=eivals(1);
    eivals(1)=temp;
  }
  double ax=sqrt(abs(1/eivals(0)));
  double bx=sqrt(abs(1/eivals(1)));
  double phix;
  if(Ax!=Cx)
    phix=1.0/2*atan(Bx/(Ax-Cx))*180/M_PI;
  else
    phix=0;
  double emix=ax*bx;

  double y1=2*sig_ypy/sqrt(sig_py);
  double py1=2*sqrt(sig_py);
  double y2=2*sqrt(sig_y);
  double py2=2*sig_ypy/sqrt(sig_y);
  double By=-2*py2/py1/(y2*py1-y1*py2);
  double Cy=y2/py1/(y2*py1-y1*py2);
  double Ay=(1+py2*py2*Cy)/y2/y2;
  CM<<Ay,   By/2,
      By/2, Cy;
  eivals = CM.selfadjointView<Eigen::Lower>().eigenvalues();
  if(sig_y<sig_py)
  {
    double temp = eivals(0);
    eivals(0)=eivals(1);
    eivals(1)=temp;
  }
  double ay=sqrt(1/eivals(0));
  double by=sqrt(1/eivals(1));
  double phiy;
  if(Ay!=Cy)
    phiy=1.0/2*atan(By/(Ay-Cy))*180/M_PI;
  else
    phiy=0;
  double emiy=ay*by;
  return vector<double>{emix,ax,bx,phix,emiy,ay,by,phiy};
}


vector<double> distribution_base1(const vector<double> &param)
{
// vector param consist the following sequencely:
//   emittence_X
//   semiaxis_X1
//   semiaxis_X2
//   tilt_X
//   emittence_Y
//   semiaxis_Y1
//   semiaxis_Y2
//   tilt_Y
  double ax=0,axs=0,ay=0,ays=0;
  ax=sqrt(  param.at(1)/param.at(2)*pow(cos(param.at(3)*M_PI/180),2)+param.at(2)/param.at(1)*pow(sin(param.at(3)*M_PI/180),2)  );
  axs=1.0/(ax*2)*((param.at(1)/param.at(2))-(param.at(2)/param.at(1)))*sin(2*param.at(3)*M_PI/180);
  ay=sqrt(  param.at(5)/param.at(6)*pow(cos(param.at(7)*M_PI/180),2)+param.at(6)/param.at(5)*pow(sin(param.at(7)*M_PI/180),2)  );
  ays=1.0/(ay*2)*((param.at(5)/param.at(6))-(param.at(6)/param.at(5)))*sin(2*param.at(7)*M_PI/180);
  double emitratio=param.at(0)/param.at(4);
//  cout<<"ax  "<<ax<<endl;
//  cout<<"axs "<<axs<<endl;
  return vector<double>{ax,axs,ay,ays,emitratio,0.0};//the last place is reserved for F 
}

void distribution_base2(const vector<double> &par,vector<double> &xy)
{
    double zetax=0,zetay=0,anglebetax=0,anglebetay=0;
    zetax=sqrt((double)rand() / RAND_MAX*par.back());
    zetay=sqrt((par.back()-zetax*zetax)/par.at(4));
    anglebetax=(double)rand() / RAND_MAX*2*M_PI;
    anglebetay=(double)rand() / RAND_MAX*2*M_PI;
    xy.at(0)=zetax  *   par.at(0)*cos(anglebetax);
    xy.at(1)=zetax  *  (par.at(1)*cos(anglebetax)-sin(anglebetax)/par.at(0));
    xy.at(2)=zetay  *   par.at(2)*cos(anglebetay);
    xy.at(3)=zetay  *  (par.at(3)*cos(anglebetay)-sin(anglebetay)/par.at(2));
    xy.at(4)=0.0;
    xy.at(5)=0.0;
}

double LambertW0(double x)
{
  //x is from 0 to 1/e
  double w1=0,w0=0;
  double z=0;
  int stepNumber=10000;
  double step=x/stepNumber;
  for(int i=0;i<stepNumber;++i)
  {
     z=z+step;
     w1=w0-(w0*pow(M_E,w0)-z)/((w0+1)*pow(M_E,w0));
     w0=w1;
  }
  return w1;
}
