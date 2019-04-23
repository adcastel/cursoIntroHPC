
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
   
    int i=0;
    int flag=0;
    int j = 0;
    int k = 0;
    double alpha = 1.0;
    double beta = 1.0;
    struct timeval start, end;
    double time;

    double mm_A[N];
    double mm_A_gpu[N];
    
    
    //Inicializacion
    for(i=0;i<N;i++){
        mm_A[i]=1;
    }

    double aux = 10.0;
    int iterations = 0;

    ////////////////////////////////////////////
    // En este caso tenemos un bucle while al que 
    // tambien se le pueden aplicar directivas de datos
    // ;)... Aqui tenemos la opción de copiar o crear 
    // la matriz que se llama GPU y la otra, pues como siempre
    // ////////////////////////////////////////
  while(iterations < 10 && aux > 0.02){

    ////////////////////////////////////////////
    //Este codigo se parece a los anteriores... ;) ;)
    ///////////////////////////////////////////
    for (i = 0; i < N; i++){
	  mm_A_gpu[i]=mm_A[i]/2.0;
	  mm_A[i]/=2.0f;
    }  
    

    ///////////////////////////////////////////
    //Y esta es la clave, necesitamos actualizar un dato
    //en la CPU desde la memoria de la GPU... Actualizamos?
    /////////////////////////////////////////////
    aux = mm_A_gpu[N-1];
    printf("Iteration %d | value %f\n",iterations++,aux);
    
}    
    
    return EXIT_SUCCESS;
}
