#include <iostream>

#include "random/random.h"
#include "data/csv_file.h"


int main(int argc, char* argv []){
    if(argc < 2){
        std::cerr << "Missing count parameter" << std::endl;
        return 1;
    }
    int count = std::stoi(argv[1]);
    NormalGenerator generator;
    generator.setSeed(43243);

    auto numbers = generator.generatePermutations(count);
    CsvFile file("permutations");
    file.addRow({"Number", "Value"});
    for(auto i = 0; i < count; ++i){
        file.addRow({std::to_string(i), std::to_string(numbers[i])});
    }
    file.write();
    return 0;
}
