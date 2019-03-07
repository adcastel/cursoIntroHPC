#include <stdio.h>
#include <stdlib.h>

/* Enlazar la libreria OpenMP */
#include <omp.h>

void imprimirVector(int *vector, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("v[i] = %d\n", vector[i]);
	}
}

void cuadrado(int *vector, int pos)
{
	vector[pos] = vector[pos]*vector[pos];
	sleep(1);
}

void doble(int *vector, int pos)
{
        vector[pos] = vector[pos]*2;
	sleep(1);
}

void secuencial(int *vector, int size)
{
	int i;
	for(i = 0; i< size; i++)
        {
                cuadrado(vector, i);
        }
	for(i=0; i<size; i++)
        {
                doble(vector, i);
        }
}

int main (int argc, char *argv[]) 
{
	int i;
	int size = 10;
	int *vector = malloc(size * sizeof(int));
	int *copia_vector = malloc(size * sizeof(int));
	double tiempo_inicio, tiempo_fin, tiempo_secuencial, tiempo_paralelo;

	// Inicializar vectores
	for(i = 0; i<size; i++)
	{
		vector[i] = i;
		copia_vector[i] = i;
	}

	// ---------------------- EJECUCION SECUENCIAL ----------------------

	// Tomar tiempo al inicio
	tiempo_inicio = omp_get_wtime();
	// Ejecucion secuencial
	secuencial(copia_vector, size);
	// Tomar tiempo al final e imprimir tiempo de ejecucion
	tiempo_fin = omp_get_wtime();
	tiempo_secuencial = tiempo_fin - tiempo_inicio;

	// ---------------------- EJECUCION PARALELA ------------------------

	// Tomar tiempo al inicio
	tiempo_inicio = omp_get_wtime();

	/*  Inicio de la region 'parallel' --> Inicializar threads      */

        #pragma omp parallel
	{
		/* Calcular (y almacenar) el cuadrado de cada elemento del vector (BUCLE PARALELO)	*/
		
		#pragma omp for
		for(i = 0; i< size; i++)
		{
			cuadrado(vector, i);
		}
	
		/* Calcular (y almacenar) el doble de cada elemento del vector (BUCLE PARALELO)		*/
		
		#pragma omp for
		for(i=0; i<size; i++)
		{
			doble(vector, i);
		}	
	}

	// Tomar tiempo al final
	tiempo_fin = omp_get_wtime();
	tiempo_paralelo = tiempo_fin - tiempo_inicio;

	// ---------------------- IMPRIMIR TIEMPOS DE EJECUCION -------------
	printf("--------------------------------------------------------------------\n");
	printf("Tiempo de ejecucion secuencial:\t%f\n", tiempo_secuencial);
	printf("Tiempo de ejecucion paralela:\t%f\n", tiempo_paralelo);
	printf("--------------------------------------------------------------------\n");
	printf("La ejecucion paralela es %f veces mas rapida.\n", tiempo_secuencial/tiempo_paralelo);
	printf("--------------------------------------------------------------------\n");
}

