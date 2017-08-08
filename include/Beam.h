#ifndef BEAM_H
#define BEAM_H

#include <vector>
#include <ostream>
#include "Particle.h"

using std::vector;

class Beam
{
  public:
    void SetField();
    void SetMatrix();
    void CaculateEmittance();
    void CaculateSigma();
    void Print(ostream &par);
    
    vector<double>      sigma           = vector<double>(6);    //6 rms sizes average <x^2>, <p_x^2>....
    vector<double>      emittance       = vector<double>(3);
    vector<double>      average         = vector<double>(6);    //6 average size of <x> <y>...
    vector<Particle>    particle;
    
    //caculate_emittance
    double frq;
    int particleNumber;
    int particleLiveNumber=0;
    double particle_ave[6];
    vector<double> 	eGamma;
    vector<double> 	eBeta;
    vector<double> 	eBetaGamma;
    vector<double> 	dw;
    vector<double> 	phi;
    double eBetaTotal     =0	,eBetaAverage     =0	,eBetaSigma     =0; 
    double eGammaTotal    =0	,eGammaAverage    =0	,eGammaSigma    =0; 
    double eBetaGammaTotal=0	,eBetaGammaAverage=0	,eBetaGammaSigma=0;
    double phiTotal   =0,phiAverage   =0,phiSigma   =0;
    double PhiGamma=0;
    double PhiBetaGamma=0;
    double sigmaz,sigmadz,dwwmax,dppmax,dbbmax;
    double TBetax,TBetay,TBetaz,TAlphax,TAlphay,TAlphaz,TGammax,TGammay,TGammaz;
    double emittancex,emittancey,emittancez,correlationx,correlationy,correlationz;
    double x_sigma,y_sigma,z_sigma,dx_sigma,dy_sigma,dz_sigma,xdx_sigma,ydy_sigma,zdz_sigma;
    
    vector<vector<double> > ParaTransfer;
  private:

};

#endif

