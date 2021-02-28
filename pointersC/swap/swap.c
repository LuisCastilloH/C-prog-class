#include <stdio.h>

void swap(char *a, char *b) {
    printf("Los apuntadores apuntan a: %c %c\n", *a, *b);
    printf("Las direccion que tiene a es %p y la de b es %p\n", a, b);
    char temp = *a;
    *a = *b;
    *b = temp;
}


int main(int argc, char *argv[]) {
    // primera opcion
    // ocurre una asignacion de un puntero a otro
    char *x = argv[1]; // el apuntador x se le asigna la direccion a la cual
                       // apunta argv[1]
    char *y = argv[2]; // el apuntador y se le asigna la direccion a la cual
                       // apunta argv[2]
    // segunda opcion
    // char *x, *y;
    // x = argv[1];
    // y = argv[2];
    printf("Los valores son: %c %c\n", *x, *y);
    printf("Las direccion que tiene x es %p y la de y es %p\n", x, y);
    /*swap(x, y);*/
    swap(argv[1], argv[2]);
    printf("Los valores son: %c %c\n", *x, *y);

    return 0;
}
