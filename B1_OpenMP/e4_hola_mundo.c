#include <stdio.h>
#include <stdlib.h>

/* Enlazar la libreria OpenMP */

........................

int main (int argc, char *argv[]) 
{
	/*  Inicio de la region 'parallel' --> Inicializar threads      */

        ........................
  	{
    		/* Todos los threads almacenan su identificador (tid) y lo imprimen 	*/

    		int tid = .............. ;
		printf("Hola mundo! Yo soy el thread %d.\n", .......... );
	
		/* Esperar a que todos los threads impriman su identificador	*/
	
		........................

		/* Solo el thread master imprime su identificador (tid) y almacena e imprime el total de threads (nthreads) 	*/
		
		........................
		{	
			int nthreads = ................. ;
			printf("\nEn total somos %d threads y yo soy el thread %d.\n\n", ......... , ......... );
		}

		/* Esperar a que el thread master imprima su identificador y el total de threads	*/
		
		........................

		/* Todos los threads se despiden	*/

		printf("Hasta pronto mundo! El thread %d se despide.\n", ............. );

	} /* Fin de la region 'parallel' --> Destruccion de threads	*/

}
