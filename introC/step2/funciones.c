#include "funciones.h"
/*
 *Always include the header file that declares something in the C file
 *that defines it
 */
#include <stdio.h>

#define TAM_ARR 5

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


