#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/time.h>
#include <unistd.h>

#define ESPERA 400000 	        // Microsegundos de espera para agotar quantum

void retardo();

/* Tamaño del buffer */
#define N 5
/* Variables globales */
int cont = 0;
sem_t sem_a;

void procedure() {
    int pausa;
    retardo(); // borrar
    sem_wait(&sem_a);
    printf("Acceso a recurso compartido");
    printf("ID %ld\n", pthread_self());
    cont++;
    printf("cont %d\n", cont);
    retardo();
    pausa = rand() % 4;
    sleep(pausa);
    sem_post(&sem_a);
}

int main(void) {
    /* Variables para los ids de los threads a crear */
    int n, i;
    printf("Ingresa cuantos procesos quieres\n");
    scanf("%d", &n);
    pthread_t *p = malloc(n*sizeof(pthread_t));

    /* Inicializamos los semaforos */
    sem_init(&sem_a,0,5);
    for(i=0; i<n; i++) {
        pthread_create(&p[i], NULL, (void *)&procedure, NULL);
    }
    
    /* Esperamos la terminación de ambos */
    for(i=0; i<n; i++) {
        pthread_join(p[i], NULL);
    }
    printf("Terminó la ejecución del ejemplo 1.\n");
    sem_destroy(&sem_a);
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