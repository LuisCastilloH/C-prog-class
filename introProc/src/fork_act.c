#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <sys/wait.h>


int main() {
    FILE *fp;
    fp = fopen("lineas.txt", "r");
    int arr[4];
    if (fp == NULL) {
        perror("Error\n");
        exit(1);
    }
    pid_t pid = fork();
    if (pid == 0) {
        pid_t pid2 = fork();
        if (pid2 == 0) {
            pid_t pid3 = fork();
            if (pid3 == 0) {
                fscanf(fp, "%d", &arr[3]);
            }
            else {
                waitpid(pid3, NULL, 0);
                fscanf(fp, "%d", &arr[2]);
            }
        }
        else {
            waitpid(pid2, NULL, 0);
            fscanf(fp, "%d", &arr[1]);
        }
    }
    else {
        waitpid(pid, NULL, 0);
        fscanf(fp, "%d", &arr[0]);
    }
    /*for(int i=0; i<4; i++) {*/
        /*fscanf(fp, "%d", &arr[i]);*/
    /*}*/

    for(int i=0; i<4; i++) {
        printf("Number is %d\n", arr[i]);
    }
    fclose(fp);

    return 0;
}
