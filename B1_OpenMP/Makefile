archivo_carga=load_OpenMP.sh

all:	e1hola e2hola e3hola e4hola e5hola e6cuadrado	

e1hola:
	./${archivo_carga}
	gcc -fopenmp e1_hola_mundo.c -o e1_hola_mundo.o

e2hola:	
	./${archivo_carga}
	gcc -fopenmp e2_hola_mundo.c -o e2_hola_mundo.o

e3hola:
	./${archivo_carga}
	gcc -fopenmp e3_hola_mundo.c -o e3_hola_mundo.o

e4hola:  
	./${archivo_carga}      
	gcc -fopenmp e4_hola_mundo.c -o e4_hola_mundo.o

e5hola:  
	./${archivo_carga}      
	gcc -fopenmp e5_hola_mundo.c -o e5_hola_mundo.o

e6cuadrado:
	./${archivo_carga}
	gcc -fopenmp e6_cuadrado_doble.c -o e6_cuadrado_doble.o

clean:
	rm e1_hola_mundo.o e2_hola_mundo.o e3_hola_mundo.o e4_hola_mundo.o e5_hola_mundo.o e6_cuadrado_doble.o
