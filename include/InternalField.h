#ifndef INTERNALFIELD
#define INTERNALFIELD
#include"Beam.h"
#include"Mesh.h"
class InternalField
{
public:
   InternalField();
   virtual void GetInternalFiled(Mesh &mesh, Beam &beam){}  //to obtaind the E_sc and B_sc form space charge
};
#endif
