#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler(int signum) {
    // Return type of the handler function should be void
    printf("\nInside handler function, caught signal %d\n", signum);
}

int main() {
    signal(SIGINT, sig_handler); // Register signal handler
    for(int i=1;;i++) { // Infinite loop
        printf("%d : Inside main function\n", i);
        sleep(1); // Delay for 1 second
    }

    return 0;
}
