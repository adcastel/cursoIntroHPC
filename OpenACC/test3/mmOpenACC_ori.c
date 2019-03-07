
/* Includes, system */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <openacc.h>

#define TOL 1e-14


/* Main */
int main(int argc, char** argv)
{    
   
    int i=0;
    int flag=0;
    int j = 0;
    int k = 0;
    double alpha = 1.0;
    double beta = 1.0;
    int n = 4096;
    struct timeval start, end;
    double time;

    if( argc > 1)
    	n=(256 < atoi(argv[1]))?atoi(argv[1]): 256;

    
    double *mm_A = (double *)malloc(n*n*sizeof(double));
    double *mm_B = (double *)malloc(n*n*sizeof(double));
    double *mm_C = (double *)malloc(n*n*sizeof(double));
    double *mm_CH = (double *)malloc(n*n*sizeof(double));
    
    if (mm_A==NULL || mm_B == NULL || mm_C==NULL || mm_CH == NULL){
        printf("Malloc error\n");
        return 1;
    }
    
    //Inicializacion
    for(i=0;i<n*n;i++){
        mm_A[i]=mm_B[i]=i;
	mm_C[i]=mm_CH[i]=0.0;
    }

//referencia
    for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
        mm_CH[i*n+j] *= beta;
        for (k = 0; k < n; k++)
          mm_CH[i*n+j] += alpha * mm_A[i*n+k] * mm_B[k*n+j];
      }
  }

    //Calculo de tiempo

    gettimeofday(&start, NULL);

    //Debemos mover los datos

    //Vienen dos bucles...

    //bucle for
    for (i = 0; i < n; i++){
    
    //bucle for
    for (j = 0; j < n; j++){
        mm_C[i*n+j] *= beta;
        for (k = 0; k < n; k++){
          mm_C[i*n+j] += alpha * mm_A[i*n+k] * mm_B[k*n+j];
	}
      }
  
    gettimeofday(&end, NULL);}
    
    
 for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
      if (fabs(mm_CH[i*n+j] - mm_C[i*n+j]) > TOL){
        flag = 1;
      }
    }
  }

    
    free(mm_A);
    free(mm_B);
    free(mm_C);
    free(mm_CH);
    
    if(flag){
        printf("Falg detected\n");
        return 1;
    }
    time = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec))/1000000.0;
    double gflops = (((2.0*n*n*n) / time )/(1024.0*1024.0*1024.0));
    printf("OpenACC %d %f %f GFLOPS\n",n, time, gflops );
    return EXIT_SUCCESS;
}
