#include <stdio.h>
#include <stdlib.h>

/* Enlazar la libreria OpenMP */

........................


void imprimirVector(int *vector, int size)
{
        int i;
        for(i=0; i<size; i++)
        {
                printf("v[%d] = %d\n", i, vector[i]);
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
        }


        // ---------------------- IMPRIMIR CONTENIDO DEL VECTOR -------------
        printf("--------------------------------------------------------------------\n");
        printf("Contenido del vector inicial:\n");
	imprimirVector(vector, size);
        printf("--------------------------------------------------------------------\n");

        // ---------------------- EJECUCION PARALELA ------------------------


        /*  Inicio de la region 'parallel' --> Inicializar threads      */

        ........................
        {
                /* Calcular (y almacenar) el cuadrado de cada elemento del vector (BUCLE PARALELO)      */

                for(i = 0; i< size; i++)
                {
                	............................
                        cuadrado(vector, i);
                }

                /* Calcular (y almacenar) el doble de cada elemento del vector (BUCLE PARALELO)         */

                for(i=0; i<size; i++)
                {
                	............................
                        doble(vector, i);
                }
        }

        // ---------------------- IMPRIMIR CONTENIDO DEL VECTOR -------------
        printf("--------------------------------------------------------------------\n");
        printf("Contenido del vector final:\n");
	imprimirVector(vector, size);
        printf("--------------------------------------------------------------------\n");
}


