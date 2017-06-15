#include "nodo.hpp"
#include "HashMap.hpp"
#include "mpi.h"
#include <unistd.h>
#include <stdlib.h>


using namespace std;
HashMap* hashMapLocal;
void nodo(unsigned int rank) {
    printf("Soy un nodo. Mi rank es %d \n", rank);

    // TODO: Implementar
    // Creo un HashMap loal
     hashMapLocal= new HashMap();
    while (true) {
        // TODO: Procesar mensaje
        //string mensaje=recv
        string comando=mensaje.substr(0,1);
        unsigned int comandoEntero= stoi(comando);
        switch(comandoEntero){
        	case COMANDO_LOAD :
        		ProcesarLoad(mensaje.substr(1,mensaje.lenght()-1));
        		trabajarArduamente();
        		//send termine
        	break;
        	default:
        	break;

        }
    }
}

void trabajarArduamente() {
    int r = rand() % 2500000 + 500000;
    usleep(r);
}
void ProcesarLoad(string parametro){
	//PREGUNTAR SI NOS TIENEN QUE ENVIAR LAS PALABRAS, EL NOMBRE DEL ARCHIVO O QUE COSA

	//Si recibimnos el nombre del archivo
	hashMapLocal->load(parametro);

}