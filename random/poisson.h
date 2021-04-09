#ifndef POISSON_GENERATOR_H
#define POISSON_GENERATOR_H

#include <cmath>

#include "exponential.h"


class PoissonGenerator{



public:

    static void setlambda(double lambda);

    static std::vector<double> generatePermutations(unsigned int size);

    static double generate();



};



#endif
