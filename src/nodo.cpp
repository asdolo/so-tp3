#include "nodo.hpp"
#include "HashMap.hpp"
#include "mpi.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string> 


using namespace std;
HashMap* hashMapLocal;
void nodo(unsigned int rank) {
    printf("Soy un nodo. Mi rank es %d \n", rank);

    // TODO: Implementar
    // Creo un HashMap loal
    hashMapLocal= new HashMap();
    while (true)
    {
        char respuesta[BUFFER_SIZE];

        MPI_Status status;
        MPI_Request request;
        // Espero que me llegue un mensaje al TAG 0
        MPI_Recv((void*) respuesta, BUFFER_SIZE, MPI_CHAR, MPI_SOURCE_CONSOLA, 0, MPI_COMM_WORLD, &status);

        // El comando está especificado en el primer caracter de respuesta, lo extraemos
        string respuestaString = respuesta;
        cout << "[nodo" << rank << "] " << "ME LLEGÓ: " << respuestaString << endl;

        string comando = respuestaString.substr(0,1);
        int numeroComando = atoi(comando.c_str());

        string nombreArchivo;
        switch(numeroComando)
        {
        	case COMANDO_LOAD:
                cout << "[nodo" << rank << "] " << "Voy a cargar el archivo" << endl;
                nombreArchivo = respuestaString.substr(1, respuestaString.length() - 1);

                hashMapLocal->load(nombreArchivo);
                cout << "[nodo" << rank << "] " << "Lo cargué" << endl;

                hashMapLocal->printAll();

                cout << "[nodo" << rank << "] " << "Voy a trabajar arduamente" << endl;
        		trabajarArduamente();
        		  
                // Le aviso a la consola que terminé
                cout << "[nodo" << rank << "] " << "Le aviso a la consola que terminé" << endl;
                MPI_Isend((void*) (&rank), 1, MPI_INT, MPI_SOURCE_CONSOLA, 1, MPI_COMM_WORLD, &request);

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