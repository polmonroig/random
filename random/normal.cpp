#include "normal.h"

/** =================================
 *               PUBLIC
 *  =================================*/


double NormalGenerator::average;
double NormalGenerator::deviation;

void NormalGenerator::setParameters(double mean, double standardDeviation){
    average = mean;
    deviation = standardDeviation;
}



double NormalGenerator::generate() {
    double s = 1;
    double v1, v2;
    while(s >= 1){
        v1 = UniformGenerator::generateProbability() * 2.0 - 1.0;
        v2 = UniformGenerator::generateProbability() * 2.0 - 1.0;
        s = v1*v1 + v2*v2;
    }
    if(s == 0) return 0;
    else{
        auto x1 = v1 * std::sqrt((-2 * std::log(s)) / s);
        x1 = deviation * x1 + average;
        return x1; // no need to calculate x2 random variable
    }
}

std::vector<double> NormalGenerator::generatePermutations(unsigned int size) {
    std::vector<double> sequence(size);
    for(auto & element : sequence){
        element = generate();
    }
    return sequence;
}
