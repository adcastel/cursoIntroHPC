
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
    int n = 1024;
    struct timeval start, end;
    double time;

    double mm_A[1024];
    double mm_A_gpu[1024];
    
    
    //Inicializacion
    for(i=0;i<n;i++){
        mm_A[i]=1;
    }

    double aux = 10.0;
    int iterations = 0;
#pragma acc data copy(mm_A[0:n]) create(mm_A_gpu[0:n])
  while(iterations < 10 && aux > 0.02){

#pragma acc kernels 
    for (i = 0; i < n; i++){
	  mm_A_gpu[i]=mm_A[i]/2.0;
	  mm_A[i]/=2.0f;
    }  
    

    #pragma acc update host(mm_A_gpu[n-1])
    aux = mm_A_gpu[n-1];
    printf("Iteration %d | value %f\n",iterations++,aux);
    
}    
    
    return EXIT_SUCCESS;
}
