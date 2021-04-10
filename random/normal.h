#ifndef NORMAL_GENERATOR_H
#define NORMAL_GENERATOR_H

#include <cmath>

#include "uniform.h"


class NormalGenerator{



public:

    static void setParameters(double mean, double standardDeviation);

    static std::vector<double> generatePermutations(unsigned int size);

    static double generate();


private:

    static double average;
    static double deviation;

};



#endif
