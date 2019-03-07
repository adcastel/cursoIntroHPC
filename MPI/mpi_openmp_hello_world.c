#include <stdio.h>
#include <omp.h>
#include "mpi.h"

int main(int argc, char** argv) {

    // Inicializamos el entorno MPI para poder usar las herramientas de comunicación que nos ofrece MPI.
    MPI_Init(NULL, NULL);

    // Obtenemos el número de procesos existentes en el comunicador.
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Obtenemos el identificador del proceso en el comunicador que ejecuta esta orden.
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Obtenemos el nombre de la máquina dónde se ejecuta el proceso que ejecuta esta orden.
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    int nthreads, tid;
    #pragma omp parallel private(nthreads, tid)
    {
        tid = omp_get_thread_num();
	nthreads = omp_get_num_threads();
        
	printf("Hello world from thread %d out of %d, in processor %s, rank %d"
            " out of %d processors\n", tid, nthreads, processor_name, world_rank, world_size);
    }
    
    MPI_Finalize();

    return 0;
}
