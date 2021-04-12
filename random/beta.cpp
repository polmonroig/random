#include "beta.h"

/** =================================
 *               PUBLIC
 *  =================================*/


BetaGenerator::BetaGenerator(double a, double b){
     alpha = a;
     beta = b;
 }

void BetaGenerator::setShape(double a, double b){
    alpha = a;
    beta = b;
}



double BetaGenerator::generate() {
    auto x1 = gamma.generate();
    auto x2 = gamma.generate();
    return x1 / (x1 + x2);
}


void ChiSquareGenerator::setSeed(BigInt seed){
    gamma.setSeed(seed);
}
