#ifndef DRIFT_H
#define DRIFT_H

#include "Element.h"
#include "Particle.h"
#include <iostream>
#include <vector>
#include <string>

class Drift : public Element 
{
  public:
    void GetField(double time,Particle &);
    void GetMatrix(Particle &);
    void SetParameter(double posit,const vector<string> & );
  private:

};

#endif //DRIFT_H
