#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct {
    int a;
    char b;
    double c;
} arg;

int suma() {
    // procesamiento...
    return 4;
}

void funcion1(void *arg2) {
    arg param = *(arg *)arg2;
    printf("Recibimos %d, %c, %.2f\n",param.a, param.b, param.c);
    printf("thread id %ld\n", pthread_self());
    sleep(2);
    printf("Ya desperte\n");
}

int main(int argc, char *argv[]) {
    printf("Estoy en el main\n");

    pthread_t tid, tid2;
    int res;
    arg args;
    args.a = 10;
    args.b = 'c';
    args.c = 1.3;
    arg args2;
    args2.a = 50;
    args2.b = 'a';
    args2.c = 9.8;

    res = pthread_create(&tid, NULL, (void *)&funcion1, (void *)&args);
    if (res != 0) {
        perror("Fallo creacion del thread\n");
    }
    res = pthread_create(&tid2, NULL, (void *)&funcion1, (void *)&args2);
    if (res != 0) {
        perror("Fallo creacion del thread\n");
    }
    void *retval;

    res = pthread_join(tid, &retval);
    if (retval == PTHREAD_CANCELED) {
        printf("The thread was canceled");
    }
    else
        printf("Returned value %p\n", retval);
    if (res != 0) {
        perror("Fallo join del thread1\n");
    }
    res = pthread_join(tid2, NULL);
    if (res != 0) {
        perror("Fallo join del thread2\n");
    }
    printf("Listooo\n");
    return 0;
}
