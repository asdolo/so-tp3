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

    for (int i =1; i <= 5; i++)
    {
        std::stringstream out;
        out << "corpus";
        out << i;
        std::ifstream archivoCorpusCorrecto(out.str().c_str());
        std::string palabra; 
    
        while (std::getline(archivoCorpusCorrecto, palabra))
        {            
            corpusCorrecto.push_back(palabra);
        }

        archivoCorpusCorrecto.close();
    }

    

    // Ordenamos la lista de palabras
    std::sort(corpusCorrecto.begin(), corpusCorrecto.end());



    std::vector<string> corpusSalidaLoad;

    std::ifstream archivoCorpusSalidaLoad("output-load.txt");
    std::string palabra; 

    while (std::getline(archivoCorpusSalidaLoad, palabra))
    {
        corpusSalidaLoad.push_back(palabra);
    }

    
    archivoCorpusSalidaLoad.close();
    
    // Ordenamos la lista de palabras
    std::sort(corpusSalidaLoad.begin(), corpusSalidaLoad.end());
    assert(std::equal(corpusCorrecto.begin(), corpusCorrecto.begin() + corpusCorrecto.size(), corpusSalidaLoad.begin()));

    return 0;
}
