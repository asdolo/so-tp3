#ifndef _NODO_H
#define _NODO_H

#define BUFFER_SIZE 1024
#define MPI_SOURCE_CONSOLA 0

#define COMANDO_LOAD 1
#define COMANDO_TRY_ADD_AND_INC 2
#define COMANDO_DO_ADD_AND_INC 3
#define COMANDO_MEMBER 4
#define COMANDO_MAXIMUM 5
#define COMANDO_QUIT 6

#define TAG_CONSOLA_SALIDA 0
#define TAG_CONSOLA_ENTRANTE 1

#define TAG_NODO_SALIDA 1
#define TAG_NODO_ENTRANTE 0
#define TAG_ADDANDINC 100

#define convertToString(x) #x


/* Función que maneja un nodo.
 * Recibe el rank del nodo.
 */
void nodo(unsigned int rank);

/* Simula un tiempo de procesamiento no determinístico.
 */
void trabajarArduamente();

#endif  /* _NODO_H */
