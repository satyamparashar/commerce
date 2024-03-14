#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    // Open a file
    fd = open("example.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Write to the file
    write(fd, "Hello, World!", 13);

    // Close the file
    close(fd);

    // Read from the file
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    read(fd, buffer, sizeof(buffer));

    printf("Read from file: %s\n", buffer);

    // Close the file
    close(fd);

    return 0;
}
