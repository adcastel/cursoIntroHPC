#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int number;
    if (world_rank == 0) {
        // Si el proceso que ejecuta esto es el rank 0, envía "number" al proceso rank 1
        number = 123456;
        MPI_Send(&number, ...);
    } else { //if (world_rank == 1) {
        // Si el proceso que ejecuta esto es el rank 1, recibe en "number" un entero del proceso rank 0
        MPI_Recv(&number, ..., MPI_STATUS_IGNORE);
        printf("Process 1 received number %d from process 0\n", number);
    }
    MPI_Finalize();
}
