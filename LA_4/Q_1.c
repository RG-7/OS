// Write a program to implement fork () system call.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed.\n");
    } else if (pid == 0) {
        printf("In Child process\n");
    } else {
        printf("In Parent process\n");
    }

    return 0;
}
