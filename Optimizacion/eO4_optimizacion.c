#include <stdio.h>
#include <stdlib.h>

/* Enlazar la libreria OpenMP */

#include <omp.h>

#define ITER 100

void imprimirVector(int *vector, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("v[%d] = %d\n", i, vector[i]);
	}
}

void opera_matrices(float **matriz_x, float **matriz_y, int i, int j, int k)
{
	int a, b;
	register int tmp = j*k; 
	a = (tmp) >> 7;
	b = i + (tmp);
	matriz_y[j][i] = a * matriz_x[j][i] + b;
}


int main (int argc, char *argv[])
{

	int i, j, k;
	int size = 1000;

	int a = 3, b = 2;
	float **matriz_x = (float **) malloc(sizeof(float*) * size );
	float **matriz_y = (float **) malloc(sizeof(float*) * size );

	double tiempo_inicio, tiempo_fin, tiempo_original, tiempo_optimizado;


	for(i=0; i<size; i++)
	{
		matriz_x[i] = (float *) malloc(sizeof(float) *size);
		matriz_y[i] = (float *) malloc(sizeof(float) *size);
	}		

	for(i=0; i<size; i++)
		for(j=0; j<size; j++)
		{
			matriz_x[i][j] = i*j;
			matriz_y[i][j] = i+j;
		}		
	// ---------------------- EJECUCION ORIGINAL ----------------------

	// Tomar tiempo al inicio
	tiempo_inicio = omp_get_wtime();

	// Ejecucion original
	for(k=0; k<ITER; k++)
		for(i=0; i<size; i++){ 
			for(j=0; j<size; j++){ 
				opera_matrices(matriz_x, matriz_y, i, j, k); 	
			}
		}
	tiempo_fin = omp_get_wtime();
	tiempo_original = tiempo_fin - tiempo_inicio;


	// ---------------------- EJECUCION OPTIMIZADO ----------------------

	// Tomar tiempo al inicio
	tiempo_inicio = omp_get_wtime();

	// Ejecucion optimizada
	for(k=0; k<ITER; k++)
		for(i=0; i<size; i++){ 
			for(j=0; j<size; j++){ 
				register int tmp;
				a = (tmp) >> 7;
				b = i + (tmp);
				matriz_y[j][i] = a * matriz_x[j][i] + b;
			}
		}

	// Tomar tiempo al final e imprimir tiempo de ejecucion
	tiempo_fin = omp_get_wtime();
	tiempo_optimizado = tiempo_fin - tiempo_inicio;



	// ---------------------- IMPRIMIR TIEMPOS DE EJECUCION -------------
	printf("--------------------------------------------------------------------\n");
	printf("Tiempo de ejecucion original:\t%f\n", tiempo_original);
	printf("--------------------------------------------------------------------\n");
	printf("Tiempo de ejecucion optimizado:\t%f\n", tiempo_optimizado);
	printf("--------------------------------------------------------------------\n");

}

