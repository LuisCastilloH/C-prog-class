#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/time.h>
#include <unistd.h>

#define ESPERA 100000 	        // Microsegundos de espera para agotar quantum

void retardo();

/* Tamaño del buffer */
#define N 5
/* Variables globales */
int a = 5;
int b = 6;
int c, d;
sem_t sem_a, sem_b, sem_c, sem_d;

void procedure0() {
    int pausa;
    retardo(); // borrar
    printf("Se lee la variable a: %d\n", a);
    //retardo();
    pausa = rand() % 4;
    sleep(pausa);
    sem_post(&sem_a);
    sem_wait(&sem_b);
    printf("Se hace la operacion c = a+b\n");
    c = a + b;
    sem_post(&sem_c);
}

void procedure1() {
    int pausa;
    retardo(); // borrar
    printf("Se lee la variable b: %d\n", b);
    //retardo();
    pausa = rand() % 4;
    sleep(pausa);
    sem_post(&sem_b);
    sem_wait(&sem_a);
    printf("Se hace la operacion d = a/b\n");
    d = a/b;
    sem_post(&sem_d);
}

void procedure2() {
    int pausa;
	sem_wait(&sem_c);
	printf("Se escribe 2 la variable 'c'\n");
	printf("c %d", c);
    retardo();
	pausa = rand() % 5;
	sleep(pausa);
    sem_wait(&sem_d);
    printf("Se escribe 4 la variable 'd'\n");
    printf("d %d", d);
}

int main(void) {
    /* Variables para los ids de los threads a crear */
    pthread_t p0, p1, p2;

    /* Inicializamos los semaforos */
    sem_init(&sem_a,0,0);
    sem_init(&sem_b,0,0);
    sem_init(&sem_c,0,0);
    sem_init(&sem_d,0,0);

    /* Creamos los threads productor() y consumidor() */
    pthread_create(&p0, NULL, (void *)&procedure0, NULL);
    pthread_create(&p1, NULL, (void *)&procedure1, NULL);
    pthread_create(&p2, NULL, (void *)&procedure2, NULL);
    /* Esperamos la terminación de ambos */
    pthread_join(p0, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    sem_destroy(&sem_a);
    printf("Terminó la ejecución del ejemplo 1.\n");
    exit(0);
}
// 	gcc -o pc.out pc.c -lpthread

void retardo() {
	struct timeval tiempo;
	struct timezone tz;
	unsigned long inicio, ahora;

	gettimeofday(&tiempo, &tz);
	ahora = inicio = tiempo.tv_sec * 1000000 + tiempo.tv_usec;

	// ESPERA microsegs
	while (ahora < inicio + ESPERA) {
	gettimeofday(&tiempo, &tz);
	ahora = tiempo.tv_sec * 1000000 + tiempo.tv_usec;
	}
}