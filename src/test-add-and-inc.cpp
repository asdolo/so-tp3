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

    corpusCorrecto.push_back("lucas");
    corpusCorrecto.push_back("federico");
    corpusCorrecto.push_back("santiago");
    corpusCorrecto.push_back("santiago");
    corpusCorrecto.push_back("federico");
    corpusCorrecto.push_back("lucas");
    corpusCorrecto.push_back("david");

        // Ordenamos la lista de palabras
    std::sort(corpusCorrecto.begin(), corpusCorrecto.end());



   std::vector<string> corpusSalidaLoad;

    std::ifstream archivoCorpusSalidaLoad("output-add-and-inc.txt");
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
