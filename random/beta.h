#ifndef BETA_GENERATOR_H
#define BETA_GENERATOR_H

#include "generator.h"
#include "gamma.h"

class BetaGenerator : public Generator{



public:

    BetaGenerator(double a=1, double b=1);

    void setShape(double a, double b);

    double generate();

    void setSeed(BigInt seed);

private:

    GammaGenerator gamma;

    double alpha;
    double beta; 

};

#endif
