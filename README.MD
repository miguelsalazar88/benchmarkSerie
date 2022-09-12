# UNIVERSIDAD SERGIO ARBOLEDA

## ESCUELA DE CIENCIAS EXACTAS E INGENIERIA

## COMPUTACIÓN PARALELA Y DISTRIBUIDA

## TALLER-PARCIAL 1

### PRESENTADO POR: DIEGO ALEJANDRO BERMÚDEZ, JESÚS CHAVES Y MIGUEL SALAZAR

Este repositorio comprende una serie de programas elaborados en el lenguaje C, con el fin
de implementar 4 benchmarks con las siguientes características:

1. Multiplicación de matrices de números tipo 'int' generados de manera no aleatoria.
2. Multiplicación de matrices de números tipo 'int' generados de manera aleatoria.
3. Multiplicación de matrices de números tipo 'double' generados de manera no aleatoria.
4. Multiplicación de matrices de números tipo 'double' generados de manera aleatoria.

INSTRUCCIONES DE INSTALACION:

1. Clonar el repositorio en un nuevo fichero.
2. En una pestaña de Terminal con ubicación en el fichero, ejecutar el Makefile
   mediante el comando < make all >. Este comando creará automáticamente los ejecutables
   de cada uno de los archivos .c.
3. Ejecutar el archivo < lanzador.pl > mediante el comando < ./lanzador.pl > o < perl lanzador.pl >

4. Para ejecutar uno de los arhivos de manera independiente: elegir cualquiera de los ejecutables y pasar como argumento el tamaño (N) de la matriz.

ARCHIVOS EN EL REPOSITORIO:

Este repositorio contiene los siguientes archivos:

1. Makefile
2. bench_functions.c
3. bench_lib.h
4. bench_project_double.c
5. bench_project_double_rmd.c
6. bench_project_int.c
7. bench_project_int_rmd.c
8. lanzador.pl
