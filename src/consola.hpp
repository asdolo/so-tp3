#ifndef _CONSOLA_H
#define _CONSOLA_H

#define BUFFER_SIZE 1024

/* Función que maneja la consola.
 * Recibe la cantidad total de nodos.
 */
void consola(unsigned int np);
unsigned int ProximoNodoLibre();
void InicializarEstructuras();
#endif  /* _CONSOLA_H */
