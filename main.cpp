#include <iostream>

#include "random/uniform.h"
#include "random/exponential.h"
#include "random/normal.h"
#include "data/csv_file.h"


int main(int argc, char* argv []){
    if(argc < 2){
        std::cerr << "Missing count parameter" << std::endl;
        return 1;
    }
    int count = std::stoi(argv[1]);
    UniformGenerator::setSeed(32423);
    ExponentialGenerator::setlambda(0.5);
    auto numbers = ExponentialGenerator::generatePermutations(count);
    CsvFile file("permutations");
    file.addRow({"Number", "Value"});
    for(auto i = 0; i < count; ++i){
        file.addRow({std::to_string(i), std::to_string(numbers[i])});
    }
    file.write();
    return 0;
}
