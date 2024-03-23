#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char** argv) {
    int fd1, fd2, sum = 0;
    char buffer[2] = "0";

    if ((fd1 = open("in1", O_RDONLY)) <= 0 || (fd2 = open("in2", O_RDONLY)) == -1) return 1;

    while (true) {
        if (read(fd1, buffer, 1) != 1) {
            close(fd1);
            remove("in1");
            break;
        }

        sum += atoi(buffer);
    }

    while (true) {
        if (read(fd2, buffer, 1) != 1) {
            close(fd2);
            remove("in2");
            break;
        }

        sum += atoi(buffer);
    }

    printf("%i\n", sum);
}