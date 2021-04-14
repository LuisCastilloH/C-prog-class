#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler(int signum) {
    printf("\nInside handler function, caught signal %d\n", signum);
}

int main() {
    pid_t pid;
    signal(SIGUSR1, sig_handler); // Register signal handler
    printf("Inside main function \n");
    pid = getpid(); // Process ID of itself
    kill(pid, SIGUSR1); // Send SIGUSR1 to itself
    printf("Inside main function \n");

    return 0;
}
