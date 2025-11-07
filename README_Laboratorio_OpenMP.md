# Proyecto Sistemas Operativos - Laboratorio OpenMP

Autor: **Yosefh Steven Peña Rodríguez**  
Clase: **Sistemas Operativos**  
Fecha: **04/11/2025**

---

## Descripción general
Este laboratorio contiene varios ejercicios de programación en lenguaje **C** que usan **OpenMP** para ejecutar código en paralelo mediante hilos.  
Cada archivo `OpenMPN.c` corresponde a un ejercicio independiente que demuestra un concepto específico de **programación paralela** y el manejo de **variables compartidas y privadas**.

---

## Estructura del proyecto

```
OpenMP.c    -> Ejemplo base: creación de hilos y mensajes paralelos
OpenMP1.c   -> Uso de variables privadas dentro de un bucle paralelo
OpenMP2.c   -> Declaración de todas las variables como privadas (private)
OpenMP3.c   -> Cálculo de sumatoria con función seno y reducción (reduction)
Makefile    -> Archivo para compilar y ejecutar todos los ejercicios
```

---

## Compilación y ejecución

### Compilar todos los ejercicios
```bash
make
```

### Compilar un ejercicio específico
Ejemplo para el ejercicio 2:
```bash
make OpenMP2
```

### Ejecutar un ejercicio específico
Ejemplo para ejecutar el ejercicio 2:
```bash
./OpenMP2
```

### Limpiar los archivos compilados
```bash
make clean
```

---

## Uso en Replit
1. Sube todos los archivos `OpenMP.c`, `OpenMP1.c`, `OpenMP2.c`, `OpenMP3.c` y el archivo `Makefile` a tu proyecto de **Replit**.  
2. Abre la consola (Shell) en Replit.  
3. Ejecuta el comando:
   ```bash
   make
   ```
4. Luego puedes correr cada ejercicio directamente, por ejemplo:
   ```bash
   ./OpenMP3 4
   ```
   *(En este caso, “4” indica el número de hilos que se desean usar.)*

---

## Notas técnicas
- Todos los programas se compilan con soporte para **OpenMP** mediante la bandera `-fopenmp`.  
- Se utilizan las siguientes librerías:
  - `<omp.h>` para paralelismo  
  - `<stdio.h>` para entrada/salida estándar  
  - `<stdlib.h>` para control de memoria  
  - `<time.h>` para medición del tiempo  
  - `<math.h>` para funciones matemáticas (`sin()`)  
- Las banderas de compilación incluyen advertencias (`-Wall -Wextra`) y optimización moderada (`-O2`).

---

## Conceptos demostrados
- Creación de regiones paralelas con `#pragma omp parallel`  
- Uso de las cláusulas `private`, `shared` y `reduction`  
- Control del número de hilos con `omp_set_num_threads()` y `OMP_NUM_THREADS`  
- División de tareas con `parallel for`  
- Medición del tiempo de ejecución con `clock()`  
- Implementación de sumatorias en paralelo utilizando funciones matemáticas  

---

## Resultado esperado
Al ejecutar cada programa se observarán diferentes comportamientos dependiendo de cómo se declaren las variables (privadas o compartidas) y del número de hilos seleccionados.  
En el **OpenMP3**, el usuario puede especificar el número de hilos, y el programa calculará la sumatoria total de la función seno, mostrando la eficiencia del paralelismo.

---

## Comandos útiles

| Comando | Descripción |
|----------|--------------|
| `make` | Compila todos los programas |
| `make OpenMPN` | Compila un ejercicio específico |
| `./OpenMPN` | Ejecuta el ejercicio N |
| `make clean` | Elimina los ejecutables |

---

### Fin del documento
