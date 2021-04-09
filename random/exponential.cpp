#include "exponential.h"

/** =================================
 *               PUBLIC
 *  =================================*/

double ExponentialGenerator::mean;

void ExponentialGenerator::setlambda(double lambda){
    mean = 1.0 / lambda;
}


double ExponentialGenerator::generate() {
    auto u = UniformGenerator::generateProbability();
    if(u == 0)u = 0.00001;

    return -mean * std::log(u);
}

std::vector<double> ExponentialGenerator::generatePermutations(unsigned int size) {
    std::vector<double> sequence(size);
    for(auto & element : sequence){
        element = generate();
    }
    return sequence;
}
