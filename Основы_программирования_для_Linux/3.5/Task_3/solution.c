#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argCount, char** args) {
    int pid = atoi(args[1]);
    char buff[256] = "";

    printf("%d\n", pid);

    while (pid != 1) {
        sprintf(buff, "/proc/%i/stat", pid);

        FILE* f = fopen(buff, "r");
        int newPid;

        fscanf(f, "%*d %*s %*s %d", &newPid);
        fclose(f);

        printf("%d\n", newPid);
        pid = newPid;
    }
}
