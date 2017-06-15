#ifndef _NODO_H
#define _NODO_H

#define BUFFER_SIZE 1024
#define MPI_SOURCE_CONSOLA 0

#define COMANDO_LOAD 1

/* Función que maneja un nodo.
 * Recibe el rank del nodo.
 */
void nodo(unsigned int rank);

/* Simula un tiempo de procesamiento no determinístico.
 */
void trabajarArduamente();

#endif  /* _NODO_H */
