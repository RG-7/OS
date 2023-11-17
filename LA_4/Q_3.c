// Write a program to implement execv() system call
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("PID of ex1.c = %d\n", getpid());
    
    char *args[] = {"hello", "world", NULL};
    execv("./Q_3_1.c", args);

    // The following statement will not be executed after execv
    printf("Back to Q_3.c\n");

    return 0;
}
