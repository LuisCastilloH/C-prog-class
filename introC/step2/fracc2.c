/*
 * @author Luis Castillo
 *
 * Agregar copyright correspondiente...
 *
 * Descripcion de tu programa
 *
 */
#include "funciones.h"

#include <stdlib.h>
#include <stdio.h>
#define TAM_ARR 5

int main() {
    Fraccion *arr = malloc(sizeof(Fraccion) * TAM_ARR);
    Fraccion fmayor, fmenor, fsuma;
    // pedimos al usuario las 5 fracciones <num> <den>
    for (int i=0; i<5; i++) {
        printf("Ingresa la fraccion #%d, con el formato <num> <den>: ", i);
        scanf("%d %d", &arr[i].num, &arr[i].den);
    }
    fmayor = mayor(arr);
    muestra("La fraccion mayor es: ", &fmayor);
    fmenor = menor(arr);
    muestra("La fraccion menor es: ", &fmenor);
    // ya puedo liberar la memoria de arr
    free(arr);
    fsuma = suma(&fmayor, &fmenor);
    muestra("La suma de la fraccion mayor y menor es: ", &fsuma);

    return 0;
}


