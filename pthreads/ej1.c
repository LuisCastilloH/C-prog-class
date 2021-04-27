#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *function1() {
    printf("Hola desde function1\n");
    sleep(5);
}

int main(int argc, char *argv[]) {
    printf("Hola desde el Main!!\n");

    int res; // variable para verificar errores
    pthread_t tid;

    res = pthread_create(&tid, NULL, function1, NULL);
    if (res != 0) {
        perror("Thread creation failed\n");
    }

    printf("Esperando a que thread termine...\n");
    res = pthread_join(tid, NULL);
    if (res != 0) {
        perror("Thread join failed\n");
    }
    printf("Thread joined\n");

    return 0;
}
