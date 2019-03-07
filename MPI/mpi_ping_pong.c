#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define SLEEP 1

int main(int argc, char** argv) {
	const int PING_PONG_LIMIT = 10;

	// Initialize the MPI environment
	MPI_Init(NULL, NULL);
	//     // Find out rank, size
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	if (world_size != 2) {
	fprintf(stderr, "World size must be two for %s\n", argv[0]);
	MPI_Abort(MPI_COMM_WORLD, 1);
	}

	int ping_pong_count = 0;
	int partner_rank = (world_rank + 1) % 2;
	while (ping_pong_count < PING_PONG_LIMIT) {
	    if (world_rank == 0) {
		ping_pong_count++;
	        sleep(SLEEP);
	        MPI_Send(&ping_pong_count, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	        printf("%d sent and incremented ping_pong_count %d to 1\n", world_rank, ping_pong_count);
                MPI_Recv(&ping_pong_count, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                sleep(SLEEP);
                printf("%d received ping_pong_count %d from 1\n", world_rank, ping_pong_count);

	    } else {
		MPI_Recv(&ping_pong_count, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	        sleep(SLEEP);
	        printf("%d received ping_pong_count %d from 0\n", world_rank, ping_pong_count);
                ping_pong_count++;
                sleep(SLEEP);
                MPI_Send(&ping_pong_count, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
                printf("%d sent and incremented ping_pong_count %d to 0\n", world_rank, ping_pong_count);
	    }
	}
	MPI_Finalize();
	return 0;
}
