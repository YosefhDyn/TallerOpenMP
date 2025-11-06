/*
 * ===============================================================
 * Hecho Por: Yosefh Steven Peña Rodriguez
 * Programa: OpenMP2.c
 * Fecha: 4/11/25
 * Tema: Programación Paralela – OpenMP (private de a y b)
 * ===============================================================
 *
 * Descripción:
 *   Bucle paralelo con variables 'i', 'a' y 'b' declaradas como
 *   private. Dentro del bucle se calcula b = a + i, pero como 'b'
 *   es privada, su valor no se refleja en la 'b' global. Por ello,
 *   al finalizar la región paralela, b mantiene su valor inicial (0).
 *   El valor esperado en secuencial sería b = 50 + 999 = 1049.
 *
 * Documentación (uso):
 *   Compilar: make
 *   Ejecutar: ./OpenMP2
 *   Limpiar:  make clean
 *
 *   Pruebas:
 *     export OMP_NUM_THREADS=1 && ./OpenMP2
 *     export OMP_NUM_THREADS=4 && ./OpenMP2
 * ===============================================================
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    const int N = 1000;
    int i;
    int a = 50;   // compartida fuera; dentro será private
    int b = 0;    // compartida fuera; dentro será private

    printf("OpenMP2: OMP_MAX_THREADS=%d\n", omp_get_max_threads());

    clock_t start = clock();

    #pragma omp parallel for private(i) private(a) private(b)
    for (i = 0; i < N; ++i) {
        /* Dentro de la región: 'a' y 'b' son privadas para cada hilo.
           Usualmente 'a' comienza indeterminada (p.ej. 0) y se calcula b = a + i.
           Al salir, la 'b' global NO se modifica. */
        b = a + i;
    }

    clock_t end = clock();
    double elapsed = (double)(end - start) / (double)CLOCKS_PER_SEC;

    printf("a = %d b = %d (Se espera a=50 b = 1049)\n", a, b);
    printf("Tiempo total: %.6f s\n", elapsed);

    return 0;
}
