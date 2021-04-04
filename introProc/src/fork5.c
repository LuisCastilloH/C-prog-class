/**
 * File: separate.c
 * ----------------
 * Here's is a program that's written in a style more conistent with
 * how fork is normally used.
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

static const int kForkFailed = 1;
static const int kWaitFailed = 2;

int main(int argc, char *argv[]) {
  printf("Before.\n");
  pid_t pid = fork();
  if(pid == -1) printf("Fork function failed.\n");
  printf("After.\n");
  if (pid == 0) {
    printf("I'm the child, and the parent will wait up for me.\n");
    return 110; // contrived exit status (not a bad number, though)
  } else {
    int status;
    printf("Parent's wait for child process with pid %d failed.\n", pid);
    waitpid(pid, &status, 0); 
    printf("Child exited with status %d.\n", status);
    return 0;
  }
}
