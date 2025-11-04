/*
 * Hecho Por: Yosefh Steven Peña Rodriguez
 * Programa: OpenMP.c
 * Fecha: 4/11/25
 * Tema: Programación Paralela – Introducción OpenMP
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main(int argc, char *argv[]) {

    // Validar número de argumentos
    if (argc != 2) {
        printf("Error\nUso: %s numHilos\n", argv[0]);
        exit(0);
    }

    int numHilos = atoi(argv[1]);            // Número de hilos a usar
    int maxHilos = omp_get_max_threads();    // Máximo soportado por la CPU

    printf("OpenMP ejecutando en cores (HyperThreading) = %d hilos maximos\n", maxHilos);
    printf("Configurando ejecución con %d hilo(s)\n\n", numHilos);

    omp_set_num_threads(numHilos);

    // Tiempo inicial global
    clock_t start = clock();

    #pragma omp parallel
    {
        int id = omp_get_thread_num(); // omp_get_thread_num da el id del hilo

        // Tiempo por hilo
        double elapsed = (double)(clock() - start) / CLOCKS_PER_SEC;

        printf("Hola Mundo desde hilo %d (tiempo: %.6f s)\n", id, elapsed);
    }

    return 0;
}

