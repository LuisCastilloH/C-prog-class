#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void hola() {
    printf("Hola desde thread\n");
    sleep(5);
}

int main(int argc, char *argv[]) {
    printf("Estoy en funcion main!!\n");
    int res;

    pthread_t tid;

    res = pthread_create(&tid, NULL, (void *)&hola, NULL);
    if (res != 0) {
        perror("Error al crear thread\n");
    }
    /*sleep(1);*/
    res = pthread_join(tid, NULL);
    if (res != 0) {
        perror("Error al hacer un join\n");
    }
    printf("Todos los threads han terminado\n");

    return 0;
}
