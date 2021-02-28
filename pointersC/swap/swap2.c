#include <stdio.h>
#include <string.h>

// funcion con parametros por referencia
void swap1(char *a, char *b) {
    printf("Los apuntadores apuntan a: %c %c\n", *a, *b);
    printf("Las direccion que tiene a es %p y la de b es %p\n", a, b);
    char temp = *a;
    *a = *b;
    *b = temp;
}

// funcion con parametros por referencia
/*void swap2(char *a[], char *b[]) {*/
void swap2(char **a, char **b) {
    printf("Los apuntadores apuntan a: %s %s\n", *a, *b);
    printf("Las direccion que tiene a es %p y la de b es %p\n", a, b);
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// swap de apuntadores
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Debes ingresar dos argumentos para realizar el swapping\n");
    }
    else if (strlen(argv[1]) == 1 && strlen(argv[2]) == 1) {
        // 1.
        // ejemplo haciendo swapping de chars

        // primera opcion
        char *t1 = argv[1]; // el apuntador t1 iguala a argv[1]
                            // (asignacion de apuntadores)
        char *t2 = argv[2]; // el apuntador t2 iguala a argv[2]
                            // (asignacion de apuntadores)
        // segunda opcion
        /*char *t1, *t2;*/
        // t1 = argv[1];
        // t2 = argv[2];
        // para hacer el swapping necesitamos pasar los valores por referencia
        // como ya tenemos apuntadores (recordando que los apuntadores apuntan
        // a un espacio de memoria) podemos pasar los apuntadores
        printf("Los valores son: %c %c\n", *t1, *t2);
        swap1(t1, t2);
        // swap1(argv[1], argv[2]); // podemos pasar directamente los apuntadores
                                 // argv[1] y argv[2]
        printf("Los valores son: %c %c\n", *t1, *t2);
    }
    else if (strlen(argv[1]) > 1 || strlen(argv[2]) > 1) {
        // 2. 
        // ejemplo haciendo swapping de arreglos de chars
        // Recordemos que un arreglo de chars es ya un apuntador de char:
        // ejemplo: char *str = "hola"
        // Para hacer el swapping tambien necesitamos pasar los valores por
        // referencia. Por lo que en este caso tenemos que usar un apuntador
        // a un apuntador de chars (arreglo de chars), por eso el **

        // primera opcion
        char **x = &argv[1]; // el apuntador a apuntador char (x) se le asigna
                            // el apuntador que apunta argv[1]
        char **y = &argv[2]; // el apuntador a apuntador char (y) se le asigna
                            // el apuntador que apunta argv[2]
        printf("%p %p\n", &argv[1], argv[1]);
        // segunda opcion
        // char **x, **y;
        // x = &argv[1];
        // y = &argv[2];
        printf("Los valores son: %s %s\n", *x, *y);
        printf("Las direccion que tiene x es %p y la de y es %p\n", x, y);
        // swap(&argv[1], &argv[2]); // podemos pasar directamente las 
                                    // direcciones de argv[1] y argv[2]
        swap2(x, y);
        printf("Los valores son: %s %s\n", *x, *y);
    }

    return 0;
}
