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

void usage(const char *progname, int opt);
/*
 *Brief description 
 *of function
 */

void fracc(int verbose);
/*
 *Brief description 
 *of function
 */

Fraccion mayor(const Fraccion *f);
/*
 *Brief description 
 *of function
 */

Fraccion menor(const Fraccion *f);
/*
 *Brief description 
 *of function
 */

Fraccion suma(const Fraccion *f1, const Fraccion *f2);
/*
 *Brief description 
 *of function
 */

void muestra(const char *msg, const Fraccion *f);
/*
 *Brief description 
 *of function
 */

#endif
