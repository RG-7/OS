// Write a program to implement wait () and exit () System Calls
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid < 0) {
        printf("Fork failed.\n");
    } else if (pid == 0) {
        // Child process
        printf("Child process, PID: %d\n", getpid());
        printf("Child is exiting.\n");
        exit(0);
    } else {
        // Parent process
        printf("Parent process, Child PID: %d\n", pid);
        printf("Parent is waiting for the child to exit...\n");
        wait(NULL);
        printf("Parent's wait is done.\n");
    }

    return 0;
}
