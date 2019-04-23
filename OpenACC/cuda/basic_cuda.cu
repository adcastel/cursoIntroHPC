#include <cuda_runtime.h>
#include <stdio.h>

#define N 16


/////////////////////////////////////////////
// Codigo que se ejecuta en la GPU
///////////////////////////////////////////////
__global__ void simple(int * A, int n){

int idx = blockIdx.x * blockDim.x + threadIdx.x;
if (idx < n){

     A[idx] = idx;
   } 
}

int main(int argc, char * argv[]){

    int i;
    ///////////////////////////////////////////////
    // Reservamos memoria en la CPU
    //////////////////////////////////////////////
    int * A = (int *)malloc(N*sizeof(int));
    int * A_gpu;
    int block_size, num_blocks;
    /////////////////////////////////////////////
    // Numero de threads por bloque
    ////////////////////////////////////////////
    block_size = 4;
    
    /////////////////////////////////////////////
    // Numero de bloques
    ////////////////////////////////////////////
    num_blocks = N/block_size;
    
    ///////////////////////////////////////////////
    // Reservamos memoria en la GPU
    //////////////////////////////////////////////
    cudaMalloc((void **)&A_gpu,N*sizeof(int));

    ///////////////////////////////////////////////
    // Movemos datos de la CPU a la GPU
    //////////////////////////////////////////////
    cudaMemcpy(A_gpu, A, N*sizeof(int), cudaMemcpyHostToDevice);

    /////////////////////////////////////////////
    // Ejecutamos el codigo con num_blocks bloques
    // de threads de block_size threads cada uno
    ///////////////////////////////////////////////
    simple<<<num_blocks,block_size>>>(A_gpu, N);
    
    ///////////////////////////////////////////////
    // Movemos datos de la GPU a la CPU
    //////////////////////////////////////////////
    cudaMemcpy(A, A_gpu, N*sizeof(int),cudaMemcpyDeviceToHost);
    
    for(i = 0; i < N-1; i++){
       printf("%d, ",A[i]);
    }
       printf("%d\n",A[N-1]);


    free(A);
    cudaFree(A_gpu);

    return 1;
}


