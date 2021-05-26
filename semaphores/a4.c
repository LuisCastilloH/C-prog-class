#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/time.h>
#include <unistd.h>

// Microsegundos de espera para agotar quantum
#define ESPERA 400000

void retardo();

/* Cantidad de equipos */
#define N 6
/* Variables globales */
sem_t sem_c, sem_p, sem_r;

void equipo_i() {
    int pausa;
    sem_wait(&sem_c);
    sem_wait(&sem_p);
    sem_wait(&sem_r);
    sem_wait(&sem_r);
    printf("Equipo con ID %ld jugando\n", pthread_self());
    retardo();
    pausa = rand() % 4;
    sleep(pausa);
    sem_post(&sem_r);
    sem_post(&sem_r);
    sem_post(&sem_p);
    sem_post(&sem_c);
    printf("Equipo con ID %ld termino su partido\n", pthread_self());
}

int main(void) {
    /* Inicializamos los semaforos */
    sem_init(&sem_c,0,2);
    sem_init(&sem_p,0,3);
    sem_init(&sem_r,0,5);

    pthread_t *p = malloc(N * sizeof(pthread_t));
    for(int i=0; i<N; i++) {
        pthread_create(&p[i], NULL, (void *)&equipo_i, NULL);
    }
    
    /* Esperamos la terminación */
    for(int i=0; i<N; i++) {
        pthread_join(p[i], NULL);
    }
    printf("Terminó la ejecución del ejercicio 4.\n");
    sem_destroy(&sem_c);
    sem_destroy(&sem_p);
    sem_destroy(&sem_r);
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