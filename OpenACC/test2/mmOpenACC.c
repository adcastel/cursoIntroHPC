
/* Includes, system */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//#include <openacc.h>

#define TOL 1e-14
#define N 512

/* Main */
int main(int argc, char** argv)
{    
   
    int i=0;
    int flag=0;
    int j = 0;
    int k = 0;
    double alpha = 1.0;
    double beta = 1.0;
    struct timeval start, end;
    double time;

    
    double mm_A[N][N] ;
    double mm_B[N][N] ;
    double mm_C[N][N] ;
    double mm_CH[N][N] ;
     
    
    //Inicializacion
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            mm_A[i][j]=mm_B[i][j]=i;
	    mm_C[i][j]=mm_CH[i][j]=0.0;
        }
    }
    if(N <= 512){
        //referencia
        for (i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                mm_CH[i][j] *= beta;
                for (k = 0; k < N; k++){
                    mm_CH[i][j] += alpha * mm_A[i][k] * mm_B[k][j];
                }
            }
        }
    }
    //Calculo de tiempo

    gettimeofday(&start, NULL);

    //////////////////////////////////////////////////////////////////
    // Este es el cÃodigo que se ejecutara¡ en la GPU. Para ello, 
    // 1. debemos identificar los datos que se utilizan. Â¿Cuales son 
    // de entrada?Â¿Y de salida?
    // 2. Poner pragmas de datos
    // 3. Identificar el codigo paralelo
    // 4. Poner pragmas de kernels y/o loops
    // 5. ¿son bucles independiente? Si lo son y el compilador dice que no...
    //Debemos mover los datos

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            mm_C[i][j] *= beta;
            for (k = 0; k < N; k++){
                mm_C[i][j] += alpha * mm_A[i][k] * mm_B[k][j];
	    }
         }
    }
    //////////////////////////////////////////////////////////////////

    gettimeofday(&end, NULL);
    
    if (N <= 512){
        for (i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                if (fabs(mm_CH[i][j] - mm_C[i][j]) > TOL){
                    flag = 1;
                }
            }
        }
    }

    
    if(flag){
        printf("Falg detected\n");
        return 1;
    }
    time = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec))/1000000.0;
    double gflops = (((2.0*N*N*N) / time )/(1024.0*1024.0*1024.0));
    printf("OpenACC %d %f %f GFLOPS\n",N, time, gflops );
    return EXIT_SUCCESS;
}
