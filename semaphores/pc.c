/* 
  --------------------------------------------------------------- 
  Problema del productos-consumidor con buffer limitado en Linux 
  implementado con threads.
  ---------------------------------------------------------------
*/
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/time.h>
#include <unistd.h>

#define TAM_MEM_1 sizeof(int)   // 1 enteros en la memoria compartida
#define TAM_MEM_3 3*sizeof(int) // 3 enteros en la memoria compartida
#define ESPERA 10000 	        // Microsegundos de espera para agotar quantum
#define MEM_COMP_ID 1234

void retardo();

/* Tamaño del buffer */
#define N 5
/* Variables globales */
int buffer[N];
int in, out;
sem_t mutex, lleno, vacio;

void productor() {
  int i, pausa;
  for(i=0;i<20;i++) {
	 printf("Productor produce info %d y la coloca en buffer[%d]\n",i, in);
	 sem_wait(&vacio); // 5 -- 4 
	 sem_wait(&mutex);
		buffer[in] = i;
		in = (in+1)%N;
		retardo();
	 sem_post(&mutex);
	 sem_post(&lleno);
	 pausa = rand() % 4;
	 sleep(pausa);
  }
  return;
}

void consumidor() {
  int i, pausa, info;
  for(i=0;i<20;i++) {
	sem_wait(&lleno);
	sem_wait(&mutex);
	  info=buffer[out];
	  printf("\tConsumidor toma info %d de buffer[%d] y la consume\n",info,out);
	  out = (out+1)%N;
	  retardo();
    sem_post(&mutex);
	sem_post(&vacio); // 4 -- 5
	pausa = rand() % 5;
	sleep(pausa);
  }
  return;
}

int main(void) {
  /* Variables para los ids de los threads a crear */
  pthread_t h1, h2;

  /* Inicializamos los semaforos */
  sem_init(&mutex,0,1);
  sem_init(&vacio,0,N);
  sem_init(&lleno,0,0);

  /* Inicializamos in y out */
  in  = 0;
  out = 0;
  /* Creamos los threads productor() y consumidor() */
  pthread_create(&h1, NULL, (void *)&productor, NULL);
  pthread_create(&h2, NULL, (void *)&consumidor, NULL);
  /* Esperamos la terminación de ambos */
  pthread_join(h1, NULL);
  pthread_join(h2, NULL);
  printf("Terminó la ejecución del productor-consumidor.\n");
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