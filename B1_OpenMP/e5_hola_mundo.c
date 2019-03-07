#include <stdio.h>
#include <stdlib.h>

/* Enlazar la libreria OpenMP */

........................

int main (int argc, char *argv[]) 
{
	int tid;

	/* Inicializar threads	*/

	........................
  	{
    		/* Cada thread almacena su identificador (tid)	*/
	
    		tid = ........................ ;

		/* Cada thread imprime su identificador (tid)	*/

		printf("Hola mundo! Soy el thread %d.\n", ........... );

	} /* Fin de la region 'parallel' --> Destruccion de threads */

}
