#ifndef GAMMA_GENERATOR_H
#define GAMMA_GENERATOR_H

#include <cmath>

#include "uniform.h"
#include "exponential.h"


class GammaGenerator{



public:

    static void setOrder(double a);

    static void setScale(double s);

    static std::vector<double> generatePermutations(unsigned int size);

    static double generate();


private:


    static double order;

    static double scale;

    static constexpr double MIN_E = 0.00001;

};



#endif
