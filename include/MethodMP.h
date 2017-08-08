#ifndef METHODMP_H
#define METHODMP_H

#include <string>
#include <QWaitCondition>
#include <QMutex>
#include "Method.h"
#include "Beam.h"
#include "Lattice.h"
#include "Mesh.h"


class MethodMP: public Method
{
  public: 
   ~MethodMP();
    MethodMP();

    void Push(Lattice &,Mesh &,Beam &, bool&, QWaitCondition&, QMutex&);
    
    double timeStep=1,timeNow=0;
    int    stepMax =1;
    int    spaceChargeFlag=0;    
    string pusherType;

  private:
};

#endif
