// Compilaremos con: mpicc mpi_hello_world.c
// Ejecutaremos con: mpiexec -n <numprocs> ./a.out

//TODOS los procesos lanzados ejecutan el siguiente código, a menos que se indique lo contrario.

#include <stdio.h>

// Incluimos la biblioteca MPI.
#include <mpi.h>

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

    // Cada proceso muestra su información.
    printf("Hello world from processor %s, rank %d"
            " out of %d processors\n",
            processor_name, world_rank, world_size);

    // Finalizamos el entorno MPI, esto debe ser lo último que hagamos en el programa, ya que a partir de aquí el comportamiento es indefinido.
    MPI_Finalize();

    return 0;
}
