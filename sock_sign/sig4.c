#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler(int signum) {
    printf("\nInside handler function, caught signal %d\n", signum);
}

int main() {
    signal(SIGUSR1, sig_handler); // Register signal handler
    printf("Inside main function \n");
    raise(SIGUSR1);
    printf("Inside main function \n");

    return 0;
}
