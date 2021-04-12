#include "beta.h"

/** =================================
 *               PUBLIC
 *  =================================*/


BetaGenerator::BetaGenerator(double a, double b){
     alpha = a;
     beta = b;
     alphaGenerator.setOrder(alpha);
     betaGenerator.setOrder(beta);
 }

void BetaGenerator::setShape(double a, double b){
    alpha = a;
    beta = b;
    alphaGenerator.setOrder(alpha);
    betaGenerator.setOrder(beta);
}



double BetaGenerator::generate() {
    double x1 = alphaGenerator.generate();
    double x2 = betaGenerator.generate();
    return x1 / (x1 + x2);
}


void BetaGenerator::setSeed(BigInt seed){
    alphaGenerator.setSeed(seed);
    betaGenerator.setSeed(seed * 2);
}
