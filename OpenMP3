/*
 * ===============================================================
 * Hecho Por: Yosefh Steven Peña Rodriguez
 * Programa: OpenMP3.c
 * Fecha: 4/11/25
 * Tema: Programación Paralela – Cálculo de Sumatorias de Función SENO
 * ===============================================================
 *
 * Descripción:
 *   Este programa calcula la sumatoria de una función basada en el
 *   seno utilizando paralelismo con OpenMP. Cada hilo ejecuta una
 *   porción de la sumatoria, y los resultados parciales se combinan
 *   mediante la cláusula reduction(+ : sum).
 *
 * Documentación (uso):
 *   Compilar: make
 *   Ejecutar: ./OpenMP3
 *   Limpiar:  make clean
 *
 *   Ejemplo de salida esperada:
 *     Número de Hilos: 4
 *     La sumatoria es: <valor>
 * ===============================================================
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>   // Librería para la función sin()

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

// ---------------------------------------------------------------
// Función f(i): calcula una pequeña sumatoria de senos
// ---------------------------------------------------------------
double f(int i) {
    int j;
    int start = i * (i + 1) / 2;
    int finish = start + i;
    double return_val = 0.0;

    for (j = start; j < finish; j++) {
        return_val += sin(j);
    }
    return return_val;
}

// ---------------------------------------------------------------
// Función principal
// ---------------------------------------------------------------
int main(int argc, char *argv[]) {
    double sum = 0.0;
    int i, n = 30000;

    #pragma omp parallel
    {
        int threads = omp_get_num_threads();

        #pragma omp master
        printf("Número de Hilos: %d\n", threads);

        #pragma omp for reduction(+ : sum)
        for (i = 0; i <= n; i++) {
            sum += f(i);
        }
    }

    printf("La sumatoria es: %.2f\n", sum);
    return 0;
}
