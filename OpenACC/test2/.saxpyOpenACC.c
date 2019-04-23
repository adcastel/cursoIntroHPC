
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
    int i;
    int flag=0;
    double alpha = 1.0;
    int n = 4096;
    struct timeval start, end;
    double time;

    if( argc > 1)
    	n=(256 < atoi(argv[1]))?atoi(argv[1]): 256;

    
    double *v_A = (double *)malloc(n*sizeof(double));
    double *v_B = (double *)malloc(n*sizeof(double));
    double *v_CH = (double *)malloc(n*sizeof(double));
    
    if (v_A==NULL || v_B == NULL || v_CH == NULL){
        printf("Malloc error\n");
        return 1;
    }
    
    //Inicializacion
    for(i=0;i<n;i++){
        v_A[i]=v_B[i]=i;
    }

//referencia
    for (i = 0; i < n; i++){
        v_CH[i] = alpha * v_A[i] + v_B[i];
  }

    //Calculo de tiempo

    gettimeofday(&start, NULL);

    //Debemos mover los datos
    {
    //viene un bucle for...
    for (i = 0; i < n; i++){
        v_B[i] = alpha * v_A[i] + v_B[i];
    }
    }  
    gettimeofday(&end, NULL);
    
    
    for (i = 0; i < n; i++){
      if (fabs(v_CH[i] - v_B[i]) > TOL){
        printf("v_CH[%d] = %f y v_B[%d] = %f\n",i,v_CH[i],i,v_B[i]);
        flag = 1;
      }
    }

    
    free(v_A);
    free(v_B);
    free(v_CH);
    
    if(flag){
        printf("Falg detected\n");
        return 1;
    }
    time = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec))/1000000.0;
    double gflops = (((2.0*n*n) / time )/(1024.0*1024.0*1024.0));
    printf("OpenACC %d %f %f GFLOPS\n",n, time, gflops );
    return EXIT_SUCCESS;
}
