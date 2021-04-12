#include <iostream>

#include "random/random.h"
#include "data/csv_file.h"


int main(int argc, char* argv []){
    if(argc < 2){
        std::cerr << "Missing count parameter" << std::endl;
        return 1;
    }
    int count = std::stoi(argv[1]);
    GeometricGenerator generator(0.8);
    generator.setSeed(43243);
    std::cout << "Generating numbers" << std::endl;
    auto numbers = generator.generatePermutations(count);
    std::cout << "Generating CSV" << std::endl;
    CsvFile file("permutations");
    file.addRow({"Number", "Value"});
    for(auto i = 0; i < count; ++i){
        file.addRow({std::to_string(i), std::to_string(numbers[i])});
    }
    std::cout << "Saving" << std::endl;
    file.write();
    return 0;
}
