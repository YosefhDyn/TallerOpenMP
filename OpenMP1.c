/*
 * ===============================================================
 * Hecho Por: Yosefh Steven Peña Rodriguez
 * Programa: OpenMP1.c
 * Fecha: 4/11/25
 * Tema: Programación Paralela – Introducción OpenMP (variables private)
 * ===============================================================
 *
 * Descripción:
 *   Crea una región paralela con un bucle for. La variable 'i' y 'a'
 *   son privadas a cada hilo. Al ser 'a' private, NO conserva su
 *   inicialización de 50 dentro de la región paralela, por lo que
 *   su valor es indefinido (típicamente 0). El último hilo que
 *   ejecute la última iteración hace: b = a + i ≈ 0 + 999 = 999.
 *   El valor esperado secuencial sería b = 50 + 999 = 1049.
 *
 * Documentación (uso):
 *   Compilar: make
 *   Ejecutar: ./OpenMP1
 *   Limpiar:  make clean
 *
 *   Pruebas (bash):
 *     export OMP_NUM_THREADS=1 && ./OpenMP1
 *     export OMP_NUM_THREADS=4 && ./OpenMP1
 * ===============================================================
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    const int N = 1000;
    int i;
    int a = 50;
    int b = 0;

    printf("OpenMP1: OMP_MAX_THREADS=%d\n", omp_get_max_threads());

    clock_t start = clock();

    #pragma omp parallel for private(i) private(a)
    for (i = 0; i < N; ++i) {
        /* 'a' es private: aquí no vale 50; suele iniciar indeterminado (p.ej. 0) */
        b = a + i; /* la última iteración típica fija b ≈ 0 + 999 = 999 */
    }

    clock_t end = clock();
    double elapsed = (double)(end - start) / (double)CLOCKS_PER_SEC;

    printf("a = %d b = %d (Se espera a=50 b = 1049)\n", a, b);
    printf("Tiempo total: %.6f s\n", elapsed);

    return 0;
}
