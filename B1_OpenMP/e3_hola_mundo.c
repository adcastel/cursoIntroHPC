#include <stdio.h>
#include <stdlib.h>

/* Enlazar la libreria OpenMP */

........................

int main (int argc, char *argv[]) 
{
	/*  Inicio de la region 'parallel' --> Inicializar threads      */

        ........................
  	{
    		/* Todos los threads almacenan su identificador (tid) y lo imprimen	*/
		
    		int tid = .................. ;
		printf("Hola mundo! Yo soy el thread %d\n", ............ );

		/* Solo el thread master imprime su identificador (tid) y almacena e imprime el total de threads (nthreads) */
		
		........................
		{	
			int nthreads = ................. ;
			printf("En total somos %d threads y yo soy el thread %d.\n", ............. , ........... );
		}

	} /* Fin de la region 'parallel' --> Destruccion de threads */

}
