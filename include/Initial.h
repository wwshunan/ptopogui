#ifndef INITIAL_H
#define INITIAL_H

#include <vector>
#include <string>
#include "Mesh.h"
#include "Beam.h"
#include "Lattice.h"
#include "MethodMP.h"
#include "mainwindow.h"

class Initial
{
  public:
    int Read(const MainWindow&);
    int InitParticle(Beam &, const MainWindow&);
    int InitLattice(Lattice &);
    int InitMesh(Mesh &);
    int InitMethodMP(MethodMP &);
 
    inline string GetMethod() {return method;};
    inline string GetPusher() {return pusher;};
    inline string GetInternalFieldMethodethod() {return internalFieldMethod;};
  private:
    //var
    //twiss
    double emitx=1e-10,alphax=0,betax=1;
    double emity=1e-10,alphay=0,betay=1;
    double emitz=1e-10,alphaz=0,betaz=1;
    vector<double> twiss=vector<double>(9);
    
    //particle
    double numofCharge=1;
    double numofMass  =1;
    double charge;
    double mass;
    int    particleNumber=1000;
    int    particleNumberPerMacroParticle;

    //displace
    vector<double> displacePos =  vector<double>(3);
    vector<double> displaceDPos = vector<double>(3);
    
    //frquency and energy and current.
    double frequency;
    double KneticE=0.035;	//MeV
    double dw=0;
    double current;
    int    spaceChargeFlag=0;

    //type
    int    dimension;                                       //to know the problem is 2D or 3D
    vector<string> distributionType = vector<string>(2);    //KV,WB,PB,GS
    
    //grid
    vector<int>  numofGrid = vector<int>(3);
    
    //control
    string method;
    string pusher;
    string internalFieldMethod;
    int stepPerCycle;
    int maxStepNumber;

    // continuous beam generation	
    int bunch_number;
    
    //storage
    vector<string> input;
};
#endif
