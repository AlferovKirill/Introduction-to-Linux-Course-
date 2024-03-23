#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* read;
    char buffer[1], command[256] = "";
    size_t zeroCount = 0;

    if (argc == 3) {
        strcat(command, argv[1]);
        strcat(command, " ");
        strcat(command, argv[2]);
    } else return 1;

    read = popen(command, "r");

    while (fread(buffer, 1, 1, read) == 1) {
        if (buffer[0] == '0') ++zeroCount;
    }

    printf("%li\n", zeroCount);
    pclose(read);
}
