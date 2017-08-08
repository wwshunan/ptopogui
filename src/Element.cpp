#include "Element.h"

void Element::SetBasicParameter(double posit, const vector<string> & param)
{
  parameterString       = param;
  position              = posit;
  length                = stod( param.at(1) );
  apertureX             = stod( param.at(2) );
  if(param.at(3)=="0")
  {
    shape=0;    //round beam pipe
  }
  else
  {
    shape=1;
    apertureY           = stod( param.at(3) ); //square beam pipe
  }
}

