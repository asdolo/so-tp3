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
    bool correr=true;
    // TODO: Implementar
    // Creo un HashMap loal
    hashMapLocal= new HashMap();
    while (correr)
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

        string restoDelMensaje;
        bool result;
        unsigned int resultado;
        string mensaje;
        switch(numeroComando)
        {
        	case COMANDO_LOAD:
                cout << "[nodo" << rank << "] " << "Voy a cargar el archivo" << endl;
                restoDelMensaje = respuestaString.substr(1, respuestaString.length() - 1);

                hashMapLocal->load(restoDelMensaje);
                cout << "[nodo" << rank << "] " << "Lo cargué" << endl;

                hashMapLocal->printAll();

                cout << "[nodo" << rank << "] " << "Voy a trabajar arduamente" << endl;
        		trabajarArduamente();
        		  
                // Le aviso a la consola que terminé
                cout << "[nodo" << rank << "] " << "Le aviso a la consola que terminé el load" << endl;
                MPI_Isend((void*) (&rank), 1, MPI_INT, MPI_SOURCE_CONSOLA, 1, MPI_COMM_WORLD, &request);

                break;

            
            case COMANDO_TRY_ADD_AND_INC:   
                cout << "[nodo" << rank << "] " << "Voy a trabajar arduamente" << endl;
                //trabajarArduamente();// No va aca, es mensaje interno
                
                cout << "[nodo" << rank << "] " << "Le aviso a la consola que quiero hacer el addAndInc yo" << endl;
                MPI_Isend((void*) (&rank), 1, MPI_INT, MPI_SOURCE_CONSOLA, 1, MPI_COMM_WORLD, &request);
                break;

            case COMANDO_DO_ADD_AND_INC:   
                cout << "[nodo" << rank << "] " << "Me aviso la consola que debo hacer el addAndInc yo" << endl;
                restoDelMensaje = respuestaString.substr(1, respuestaString.length() - 1);
                hashMapLocal->addAndInc(restoDelMensaje);

                cout << "[nodo" << rank << "] " << "Voy a trabajar arduamente" << endl;
                trabajarArduamente();
                cout << "[nodo" << rank << "] " << "Le aviso a la consola que terminé el addAndInc" << endl;
                MPI_Isend((void*) (&rank), 1, MPI_INT, MPI_SOURCE_CONSOLA, 100, MPI_COMM_WORLD, &request);
                break;
            case COMANDO_MEMBER:
                restoDelMensaje = respuestaString.substr(1, respuestaString.length() - 1);
                cout << "[nodo" << rank << "] " << "Me aviso la consola que debo buscar la palabra " << restoDelMensaje << endl;
                result= hashMapLocal->member(restoDelMensaje);
                if (result)
                {
                    resultado=1;
                }else{
                    resultado=0;
                }
                cout << "[nodo" << rank << "] " << "Voy a trabajar arduamente" << endl;
                trabajarArduamente();
                cout << "[nodo" << rank << "] " << "Le aviso a la consola que el resultado de member es:" << resultado << endl;
                MPI_Isend((void*) (&resultado), 1, MPI_INT, MPI_SOURCE_CONSOLA, 1, MPI_COMM_WORLD, &request);
                break;
            case COMANDO_MAXIMUM:
                cout << "[nodo" << rank << "] " << "Me aviso la consola que debo enviar todas las palabras para maximum "<< endl;             
                 
                for (HashMap::iterator it= hashMapLocal->begin(); it!=hashMapLocal->end(); it++)
                {
                    mensaje=*it;

                    MPI_Isend((void*) mensaje.c_str(), mensaje.size() + 1, MPI_CHAR, MPI_SOURCE_CONSOLA, 1, MPI_COMM_WORLD, &request);
                }
                mensaje="0";
                MPI_Isend((void*) mensaje.c_str(), mensaje.size() + 1, MPI_CHAR, MPI_SOURCE_CONSOLA, 1, MPI_COMM_WORLD, &request);
                break;
                case COMANDO_QUIT:
                    correr=false;
                    //ADIOS!
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