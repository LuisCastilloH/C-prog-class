#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/time.h>
#include <unistd.h>

// Microsegundos de espera para agotar quantum
#define ESPERA 400000

void retardo();

/* Cantidad de autos */
#define N 60
/* Variables globales */
sem_t sem_puerta, sem_lug_disp, sem_lug_ocup;
int lugares_disp = 50;

void entra() {
    int pausa;
    sem_wait(&sem_lug_disp);
    sem_wait(&sem_puerta);
    printf("Carro con ID %ld se estaciona\n", pthread_self());
    lugares_disp -= 1;
    printf("Lugares disp: %d\n", lugares_disp);
    sem_post(&sem_puerta);
    sem_post(&sem_lug_ocup);
}

void sale() {
    int pausa;
    sem_wait(&sem_lug_ocup);
    sem_wait(&sem_puerta);
    printf("Carro con ID %ld sale\n", pthread_self());
    lugares_disp += 1;
    printf("Lugares disp: %d\n", lugares_disp);
    sem_post(&sem_puerta);
    sem_post(&sem_lug_disp);
}

void carro() {
    int pausa;
    entra();
    retardo();
    pausa = rand() % 4;
    sleep(pausa);
    sale();
}

int main(void) {
    /* Inicializamos los semaforos */
    sem_init(&sem_puerta,0,1);
    sem_init(&sem_lug_disp,0,50);
    sem_init(&sem_lug_ocup,0,0);

    pthread_t *p = malloc(N * sizeof(pthread_t));
    for(int i=0; i<N; i++) {
        pthread_create(&p[i], NULL, (void *)&carro, NULL);
    }
    
    /* Esperamos la terminación */
    for(int i=0; i<N; i++) {
        pthread_join(p[i], NULL);
    }
    printf("Terminó la ejecución del ejercicio 4.\n");
    sem_destroy(&sem_puerta);
    sem_destroy(&sem_lug_disp);
    sem_destroy(&sem_lug_ocup);
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