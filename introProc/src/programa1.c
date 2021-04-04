/* progmc1.c */
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>

#define SHMKEY 75

int main (void){
    int shmid;
    char *addr;
    int i,*pint;
    /* Crear la región de memoria y obtener la dirección */
    shmid = shmget(SHMKEY, sizeof(int), 0666 | IPC_CREAT);
    /* Enlazar región al espacio de direccionamiento del proceso */
    pint = (int *)shmat(shmid, (void *)0, 0); /* Reservar addr */
    printf("Inicando ejecución progmc1\n");
    /* Código de la sincronización */
    for(i=0;i<30;i++) {
       printf("Incrementando memoria compartida %d\n", *pint);
       (*pint)++;
       sleep (1);
    }
    /* Separar la región del espacio de direccionamiento del proceso */
    shmdt(pint);
    /* Eliminar la región de memoria compartida */
    shmctl(shmid, IPC_RMID, 0); /* Esta op también la puede realizar otro proc */
    return 0;
} /* fin de la función main */
