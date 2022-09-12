#ifndef BENCH_H_INCLUDED
#define BENCH_H_INCLUDED
/**********************************************************************************
 * Fecha: 9 Agosto 2022
 * Autor: Diego Bermudez, Jesus Chaves, Miguel Salazar
 * Tema: Construccion Benchmark Multiplicacion de matrices
**********************************************************************************/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>

/* Función evaluación inicio de tiempo */
void punto_prueba_inicial();

/* Función evaluación inicio de tiempo, impresión de resultados */
void punto_prueba_final();

/* Multiplicacion de matrices clasica */
void multiplicacionMM_1(int *matrizA, int *matrizB, int *matrizC, int n);

/* Multiplicacion de matrices punteros */
void multiplicacion_int(int *matrizB, int *matrizA, int *matrizC, int n);

/* Benchmark 01 multiplicación de double */
void multiplicacion_double(double *matrizB, double *matrizA, double *matrizC, int n);

/* Funcion de llenado */
void inicializacion_int(int *matrizA, int *matrizB, int *matrizC, int n);

/* Funcion para crear aleatorios de tipo entero */
int random_int();

/* Funcion para crear aleatorios de tipo double */
double random_double();

/* Funcion de llenado de matrices double */
void inicializacion_double(double *matrizA, double *matrizB, double *matrizC, int n);

/* Funcion de llenado de matrices enteros */
void inicializacion_int_rmd(int *matrizA, int *matrizB, int *matrizC, int n);

/* Funcion de llenado de matrices con numeros flotantes aleatorios*/
void inicializacion_double_rmd(double *matrizA, double *matrizB, double *matrizC, int n);

/* Funcion impresion */
void impresion_int(int *matriz, int n);

/* Funcion impresion matrices de double */
void impresion_double(double *matriz, int n);


#endif
