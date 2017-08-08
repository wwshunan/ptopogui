#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <vector>
#include "Particle.h"

class Element
{
  public:
    virtual void GetField(double time,Particle &)                       {}
    virtual void GetMatrix(Particle &)                                  {}
    virtual void SetParameter(double posit, const vector<string> & )    {}
    void         SetBasicParameter(double posit, const vector<string> & );
    
    vector<string>      parameterString;        //store the information of element in one line in "lattice.txt"
    
    double              apertureX;              //to store the aperture of element
    double              apertureY;
    int                 shape;                  //0 means a round element, 1: means a rect element
  protected:
    vector<double>      parameter;
    string              name;
    double              position;               //to store the start position of each element	
    double              length;                 //to store the length element
};
#endif
