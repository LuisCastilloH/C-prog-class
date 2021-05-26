#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/time.h>
#include <unistd.h>

#define ESPERA 100000 	        // Microsegundos de espera para agotar quantum

void retardo();

/* Variables globales */
int a, b;
sem_t semaforo_a;

void procedure1() {
    int pausa;
    retardo(); // borrar
    printf("Se asigna el valor 5 a la variable 'a'\n");
    a = 5;
    //retardo();
    pausa = rand() % 4;
    sleep(pausa);
    sem_post(&semaforo_a);
}

void procedure2() {
    int pausa;
	sem_wait(&semaforo_a);
	printf("Se hace la asignacion de 'b' incluyendo la variable 'a'\n");
	b = a/3;
    retardo();
	pausa = rand() % 5;
	sleep(pausa);
    sem_post(&semaforo_a);
}

int main(void) {
    /* Variables para los ids de los threads a crear */
    pthread_t p1, p2;

    /* Inicializamos los semaforos */
    sem_init(&semaforo_a,0,0);

    /* Creamos los threads productor() y consumidor() */
    pthread_create(&p1, NULL, (void *)&procedure1, NULL);
    pthread_create(&p2, NULL, (void *)&procedure2, NULL);
    /* Esperamos la terminación de ambos */
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
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