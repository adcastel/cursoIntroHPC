
/* Includes, system */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <openacc.h>

#define TOL 1e-14
#define N 1024

/* Main */
int main(int argc, char** argv)
{    
    int i;
    int flag=0;
    double alpha = 2.0;
    struct timeval start, end;
    double time;


    
    double v_A[N];
    double v_CH[N];
    
    
    //Inicializacion
    for(i = 0; i < N; i++){
        v_A[i]=i;
    }

    //referencia
    for (i = 0; i < N; i++){
        v_CH[i] = v_A[i] * alpha;
    }

    //Calculo de tiempo
    gettimeofday(&start, NULL);

    //////////////////////////////////////////////////////////////////
    // Este es el cÃodigo que se ejecutara¡ en la GPU. Para ello, 
    // 1. debemos identificar los datos que se utilizan. Â¿Cuales son 
    // de entrada?Â¿Y de salida?
    // 2. Poner pragmas de datos
    // 3. Identificar el codigo paralelo
    // 4. Poner pragmas de kernels
    //Debemos mover los datos
    
    //pragma acc...
    {
        //bucle for
        //pragma acc...
        for (i = 0; i < N; i++){
            v_A[i] = alpha * v_A[i];
        }
    }
    /////////////////////////////////////////////////////////////////
  
    gettimeofday(&end, NULL);
    
    
    for (i = 0; i < N; i++){
      if (fabs(v_CH[i] - v_A[i]) > TOL){
        printf("v_CH[%d] = %f y v_A[%d] = %f\n",i,v_CH[i],i,v_A[i]);
        flag = 1;
      }
    }

    
    if(flag){
        printf("Falg detected\n");
        return 1;
    }
    time = ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec))/1000000.0;
    double gflops = (((N) / time )/(1024.0*1024.0*1024.0));
    printf("OpenACC %d %f %f GFLOPS\n",N, time, gflops );
    return EXIT_SUCCESS;
}
