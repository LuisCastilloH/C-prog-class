#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define M 4
#define N 4
#define THREADS 4

int A[M][N] = {{1,2,3,4}, {5,6,7,8}, {11,22,33,44}, {9,8,7,6}};
int B[M][N] = {{3,5,6,8}, {3,7,9,0}, {1,1,1,1}, {12,34,98,10}};
int C[M][N];

void *partial_sum(void *arg) {
    int core = *(int *) arg;
    printf("Index recibido %d\n", core);
    for(int i=core*M/THREADS; i<(core+1) * THREADS/4; i++) {
        for(int j=0; j<N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main(int argc, char *argv[]) {
    printf("Hola desde el main!!\n");
    pthread_t tid[THREADS];
    int res;
    int step = 0;

    for(int i=0; i<THREADS; i++) {
        res = pthread_create(&tid[i], NULL, partial_sum, (void *) &step);
        printf("step %d\n", step);
        if (res != 0) {
            perror("Thread creation failed\n");
            exit(1);
        }
        step++;
    }
    for(int i=0; i<THREADS; i++) {
        res = pthread_join(tid[i], NULL);
        if (res != 0) {
            perror("Thread join failed\n");
            exit(1);
        }
    }
    printf("Threads joined\n");
    printf("Result\n");
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            printf("%d  ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
