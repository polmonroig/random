#ifndef EXPONENTIAL_GENERATOR_H
#define EXPONENTIAL_GENERATOR_H

#include <cmath>

#include "uniform.h"


class ExponentialGenerator{



public:

    static void setlambda(double lambda);

    static std::vector<double> generatePermutations(unsigned int size);

    static double generate();


private:


    static double mean;

    static constexpr double MIN_E = 0.00001;

};



#endif
