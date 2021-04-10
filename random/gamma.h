#ifndef GAMMA_GENERATOR_H
#define GAMMA_GENERATOR_H


#include "generator.h"
#include "uniform.h"
#include "exponential.h"


class GammaGenerator : public Generator{



public:

    void setOrder(double a);

    void setScale(double s);

    double generate();

    void setSeed(BigInt seed);

private:

    ExponentialGenerator exponential;
    UniformGenerator uniform;


    double order;

    double scale;

    static constexpr double MIN_E = 0.00001;

};



#endif
