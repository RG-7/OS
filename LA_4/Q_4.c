// Write a program to implement the system calls open (), read (), write () & close ().
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>  // Include the necessary header for lseek

int main() {
    int fd;
    char buffer[80];
    static char message[] = "Hello";

    fd = open("myfile.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);  // Added O_CREAT and file permissions
    if (fd != -1) {
        printf("myfile.txt opened with read/write access\n");

        write(fd, message, sizeof(message));
        lseek(fd, 0, SEEK_SET);  // Changed 0 to SEEK_SET for clarity
        read(fd, buffer, sizeof(message));

        printf("%s — was written to myfile.txt \n", buffer);

        close(fd);
    }

    return 0;
}
