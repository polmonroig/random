#include "uniform.h"


/** =================================
 *               PUBLIC
 *  =================================*/

BigInt UniformGenerator::seed;

void UniformGenerator::setSeed(BigInt s){
    seed = s;
}

float UniformGenerator::generateProbability(){
    return (generate() * 1.0) / m;
}

BigInt UniformGenerator::generate() {
    auto r = (seed * a + c) % m;
    seed = r;
    return r;
}

std::vector<BigInt> UniformGenerator::generatePermutations(unsigned int size) {
    std::vector<BigInt> sequence(size);
    for(auto & element : sequence){
        element = generate();
    }
    return sequence;
}
