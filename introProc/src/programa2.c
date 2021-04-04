/* progmc2.c */
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHMKEY 75

int main (void) {
    int shmid;
    int *pint;
    int i;
    /* Obtener dirección de la región de memoria */
    shmid = shmget(SHMKEY, sizeof(int), 0666 | IPC_CREAT);
    /* Enlazar región al espacio de direccionamiento del proceso */
    pint = (int *)shmat(shmid, (void *)0, 0); /* Reservar addr */
    /* consultando contenido de la primera dirección distinto de 0 */
    for(i=0;i<30;i++){
        printf("La memoria compartida contiene un %d\n", *pint);
        sleep(1); /* Esperar 1 segundo */
    }
    /* Separar la región del espacio de direccionamiento del proceso */
    shmdt (pint);
    return 0;
} /* fin de la función main */
