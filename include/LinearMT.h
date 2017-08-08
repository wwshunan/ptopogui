#ifndef LINEARMT_H
#define LINEARMT_H
#include "Eigen/Dense"
#include "Beam.h"
#include "Pusher.h"
#include"Lattice.h"
#include <cmath>
using namespace Eigen;
class LinearMT :public Pusher
{
public:
    void Update(Beam &beam, Lattice &lattice, double  stepinElement);  
};


#endif

