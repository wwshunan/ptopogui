#ifndef PUSHER_H
#define PUSHER_H

#include "Beam.h"
class Pusher
{
  public:
    virtual void Update(double timestep, Beam &)        {}

};
#endif

