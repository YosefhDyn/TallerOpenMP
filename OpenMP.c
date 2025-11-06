/*
 * ===============================================================
 * Hecho Por: Yosefh Steven Peña Rodriguez
 * Programa: OpenMP.c
 * Fecha: 4/11/25
 * Tema: Programación Paralela – Introducción OpenMP
 * ===============================================================
 *
 * Descripción:
 *   Este programa utiliza OpenMP para crear hilos de ejecución
 *   en paralelo, donde cada hilo imprime un mensaje con su ID.
 *   Además, se mide el tiempo total de ejecución del bloque paralelo.
 *
 * Documentación:
 *   Compilación: make
 *   Ejecución:   ./OpenMP
 *   Limpieza:    make clean
 * ===============================================================
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    printf("OpenMP ejecutando con %d hilos máximos\n\n", omp_get_max_threads());

    // Inicia la medición del tiempo
    clock_t start = clock();

    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        printf("Hola Mundo desde el hilo %d\n", id);
    }

    // Finaliza la medición del tiempo
    clock_t end = clock();
    double tiempo = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nTiempo total de ejecución: %.5f segundos\n", tiempo);

    return 0;
}

