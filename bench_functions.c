/**********************************************************************************
 * Fecha: 9 de gosto 2022
 * Autor: Diego Barmudez, Jesus Chaves, Miguel Salazar
 * Tema: Construccion Benchmark Multiplicacion de matrices
**********************************************************************************/
#include "bench_lib.h"

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <errno.h>
#include <stdint.h>
#include <unistd.h>

struct timespec inicioCuenta, finCuenta;

/* Función evaluación inicio de tiempo */
void punto_prueba_inicial(){
    clock_gettime(CLOCK_MONOTONIC, &inicioCuenta);
}

/* Función evaluación inicio de tiempo, impresión de resultados */
void punto_prueba_final(){
    double total_time;
    clock_gettime(CLOCK_MONOTONIC, &finCuenta);
    total_time = (finCuenta.tv_sec - inicioCuenta.tv_sec)* 1e9;
    total_time = (total_time + finCuenta.tv_nsec - inicioCuenta.tv_nsec)* 1e-9;
    printf("%f\n", total_time);
}

/* Funcion para crear aleatorios de tipo entero */
int random_int(){
    int min = 0, max = 9;
    static int flag = -1;
    if ((flag = (flag<0))){
        srand(time(NULL) + getpid());
    }
    if (min > max){
        return errno = EDOM, NAN;
    }
    return min + (int)rand()/((int)RAND_MAX/(max-min));
}

/* Funcion para crear aleatorios de tipo double */
double random_double(){
    double min = 0.001, max = 9.99;
    static int flag = -1.00;
    if ((flag = (flag<0))){
        srand(time(NULL) + getpid());
    }
    if (min > max){
        return errno = EDOM, NAN;
    }
    return min + (double)rand()/((double)RAND_MAX/(max-min));
}

/* Funcion de llenado de matrices enteros */
void inicializacion_int(int *matrizA, int *matrizB, int *matrizC, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrizA[i+j*n] = 2*(i+j);
            matrizB[i+j*n] = 2*i+3*j;
            matrizC[i+j*n] = 0;
        }
    }
}

/* Funcion de llenado de matrices enteros aleatorios*/
void inicializacion_int_rmd(int *matrizA, int *matrizB, int *matrizC, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrizA[i+j*n] = random_int();
            matrizB[i+j*n] = random_int();
            matrizC[i+j*n] = 0;
        }
    }
}

/* Funcion de llenado de matrices double */
void inicializacion_double(double *matrizA, double *matrizB, double *matrizC, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrizA[i+j*n] = 2*(i+j);
            matrizB[i+j*n] = 2*i+3*j;
            matrizC[i+j*n] = 0;
        }
    }
}

/* Funcion de llenado de matrices con double aleatorios*/
void inicializacion_double_rmd(double *matrizA, double *matrizB, double *matrizC, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrizA[i+j*n] = random_double();
            matrizB[i+j*n] = random_double();
            matrizC[i+j*n] = 0;
        }
    }
}

/* Benchmark 01 */
void multiplicacionMM_1(int *matrizA, int *matrizB, int *matrizC, int n){
    int acum;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            acum = 0;
            for (int k = 0; k < n; k++){
                acum += matrizA[j+k*n] * matrizB[k+i*n];
            }
            matrizC[j+i*n] = acum;
        }
    }
}

/* Benchmark 01 multiplicación de enteros */
void multiplicacion_int(int *matrizB, int *matrizA, int *matrizC, int n){
    int acum;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            acum = 0;
            /* Punteros auxiliares */
            int *pA, *pB;
            pA = matrizA + (i*n);
            pB = matrizB + j;
            for (int k = 0; k < n; k++, pA++, pB+=n){
                acum += (*pA * *pB);
            }
            matrizC[j+i*n] = acum;
        }
    }
}

/* Benchmark 01 multiplicación de double */
void multiplicacion_double(double *matrizB, double *matrizA, double *matrizC, int n){
    double acum;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            acum = 0;
            /* Punteros auxiliares */
            double *pA, *pB;
            pA = matrizA + (i*n);
            pB = matrizB + j;
            for (int k = 0; k < n; k++, pA++, pB+=n){
                acum += (*pA * *pB);
            }
            matrizC[j+i*n] = acum;
        }
    }
}

/* Funcion impresion matrices de enteros */
void impresion_int(int *matriz, int n){
    if (n <= 10){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                printf("%d\t", matriz[i+j*n]);
            }
            printf("\n");
        }
        printf("\n------------------------------------------\n");
    }
}

/* Funcion impresion matrices de double */
void impresion_double(double *matriz, int n){
    if (n <= 10){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                printf("%f\t", matriz[i+j*n]);
            }
            printf("\n");
        }
        printf("\n------------------------------------------\n");
    }
}
