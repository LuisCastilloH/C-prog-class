/*
 * @author Luis Castillo
 *
 * Agregar copyright correspondiente...
 *
 * Descripcion de tu programa
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define TAM_ARR 5

typedef struct {
    int num;
    int den;
} Fraccion;

Fraccion mayor(const Fraccion *f);

Fraccion menor(const Fraccion *f);

Fraccion suma(const Fraccion *f1, const Fraccion *f2);

void muestra(const char *msg, const Fraccion *f);

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

Fraccion
mayor (const Fraccion *f)
{
    double max = f[0].num / (double) f[0].den;
    double temp_max;
    int max_index = 0;
    for (int i=1; i<TAM_ARR; i++) {
        temp_max = f[i].num / (double) f[i].den;
        if (temp_max > max) {
            max = temp_max;
            max_index = i;
        }
    }
    return f[max_index];
}

Fraccion
menor (const Fraccion *f)
{
    double min = f[0].num / (double) f[0].den;
    double temp_min;
    int min_index = 0;
    for (int i=1; i<TAM_ARR; i++) {
        temp_min = f[i].num / (double) f[i].den;
        if (temp_min < min) {
            min = temp_min;
            min_index = i;
        }
    }
    return f[min_index];
}

Fraccion
suma (const Fraccion *f1, const Fraccion *f2)
{
    Fraccion res;
    res.num = f1->num*f2->den + f2->num*f1->den;
    res.den = (*f1).den * (*f2).den;
    // (*f1).den es lo mismo a f1->den
    return res;
}

void
muestra (const char *msg, const Fraccion *f)
{
    printf("%s %d / %d\n", msg, f->num, f->den);
}



