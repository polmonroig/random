#include "gamma.h"

/** =================================
 *               PUBLIC
 *  =================================*/

double GammaGenerator::order;
double GammaGenerator::scale;

void GammaGenerator::setOrder(double a){
    order = a;
}

void GammaGenerator::setScale(double s){
    scale = s;
}

double GammaGenerator::generate() {
    if(order == 1){
        return ExponentialGenerator::generate() * GammaGenerator::scale;
    }
    double x = 0;
    double y;
    double keep_iterating = true;
    // it is performed < 1.902 when a >= 3
    while(keep_iterating){
        auto u = UniformGenerator::generateProbability();
        if(u == 0)u = MIN_E;
        y = std::tan(M_PI * u);
        x = std::sqrt(2.0 * order  - 1.0) * y + order - 1;
        keep_iterating = x <= 0;
        if(!keep_iterating){
            auto v = UniformGenerator::generateProbability();
            if(v == 0)v = MIN_E;
            double value = (1 + y*y) * std::exp((order - 1) * std::log(x / (order - 1)) - std::sqrt(2 * order - 1) * y);
            keep_iterating = v > value;
        }

    }


    return x * GammaGenerator::scale;
}

std::vector<double> GammaGenerator::generatePermutations(unsigned int size) {
    std::vector<double> sequence(size);
    for(auto & element : sequence){
        element = generate();
    }
    return sequence;
}
