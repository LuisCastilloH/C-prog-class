#ifndef FUNCIONES_DOT_H
#define FUNCIONES_DOT_H
/*
 *
 *The previous is an include guard. It prevents the file from being
 *included twice.
 *
 */

typedef struct {
    int num;
    int den;
} Fraccion;

Fraccion mayor(const Fraccion *f);

Fraccion menor(const Fraccion *f);

Fraccion suma(const Fraccion *f1, const Fraccion *f2);

void muestra(const char *msg, const Fraccion *f);

#endif
