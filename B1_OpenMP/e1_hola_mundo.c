#include <stdio.h>
#include <stdlib.h>

/* Enlazar la libreria OpenMP */

#include <omp.h>

int main (int argc, char *argv[]) 
{
	/*  Inicio de la region 'parallel' --> Inicializar threads 	*/
#include <omp.h>
	#pragma omp parallel
  	{

    		/* Cada thread almacena su identificador (tid) y el total de threads (nthreads) */

    		int tid = omp_get_thread_num() ;
    		int nthreads = omp_get_num_threads ;

		/* Cada thread imprime su identificador (tid) y el total de threads (nthreads)	*/

		printf("Hola mundo! En total somos %d threads y yo soy el thread %d.\n", nthreads , tid );

	} /* Fin de la region 'parallel' --> Destruccion de threads	*/
}

