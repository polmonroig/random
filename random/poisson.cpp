#include "poisson.h"

/** =================================
 *               PUBLIC
 *  =================================*/



void PoissonGenerator::setlambda(double lambda){
    ExponentialGenerator::setlambda(lambda);
}


double PoissonGenerator::generate() {
    double sum = 0;
    int counter = 0;
    while(sum < 1){
        sum += ExponentialGenerator::generate();
        counter += 1;
    }

    return counter - 1;
}

std::vector<double> PoissonGenerator::generatePermutations(unsigned int size) {
    std::vector<double> sequence(size);
    for(auto & element : sequence){
        element = generate();
    }
    return sequence;
}
