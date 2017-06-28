#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>    // std::sort
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <sstream>      // std::stringstream
#include <assert.h>      // std::stringstream
#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
    
    std::vector<string> corpusCorrecto;

    corpusCorrecto.push_back("<pedro,6>");
    std::vector<string> corpusSalidaLoad;

    std::ifstream archivoCorpusSalidaLoad("output-maximum.txt");
    std::string palabra; 

    while (std::getline(archivoCorpusSalidaLoad, palabra))
    {
        corpusSalidaLoad.push_back(palabra);
    }

    
    archivoCorpusSalidaLoad.close();
    
    
    assert(std::equal(corpusCorrecto.begin(), corpusCorrecto.begin() + corpusCorrecto.size(), corpusSalidaLoad.begin()));

    return 0;
}
