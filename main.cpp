#include <iostream>
#include "loadSats/LoadSat.h"
#include <filesystem>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::filesystem::directory_iterator;

int main() {
    std::string path = R"(../InputData)";

    for (const auto &file: directory_iterator(path)) {
        cout << file.path() << endl;


        auto loader = LoadSat();
        Network network = loader.LoadFromFile(file.path().string());
        network.printStats();
        network.generateBest(file);
        //getchar();
    }

    return 0;
}
