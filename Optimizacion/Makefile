
all:	e1 e2 e3 e4 e5 e6 e5_opt e6_opt

e1: 
	gcc -fopenmp eO1_optimizacion.c -o e1

e2:	
	gcc -fopenmp eO2_optimizacion.c -o e2

e3:
	gcc -fopenmp eO3_optimizacion.c -o e3

e4:  
	gcc -fopenmp eO4_optimizacion.c -o e4

e5:  
	gcc -fopenmp eO5_optimizacion.c -o e5

e6:  
	gcc -fopenmp eO6_optimizacion.c -o e6

e5_opt:  
	gcc -O3 -fopenmp eO5_optimizacion.c -o e5_opt

e6_opt:  
	gcc -O3 -fopenmp eO6_optimizacion.c -o e6_opt

clean:
	rm e1 e2 e3 e4 e5 e6 e5_opt e6_opt
