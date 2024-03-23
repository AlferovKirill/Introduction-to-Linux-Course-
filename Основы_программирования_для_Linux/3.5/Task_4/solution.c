#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int countProcesses(int pid) {
    int childPid;
    int count = 0;

    char command[256];
    FILE* fd;

    sprintf(command, "ps -o %%p --ppid %d", pid);
    fd = popen(command, "r");
    fscanf(fd, "%*s");

    while (fscanf(fd, "%d", &childPid) != EOF) {
        ++count;
        count += countProcesses(childPid);
    }

    pclose(fd);
    return count;
}

int main(int argc, char** argv) {
    int pid = atoi(argv[1]);
    int count = countProcesses(pid) + 1;

    printf("%d\n", count);
}
