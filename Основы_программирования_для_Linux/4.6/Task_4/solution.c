#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void mySignalHandler(int signalNum) {
    exit(0);
}

int main() {
    int pid = fork();
    if (pid != 0) {
        return 0;
    } else {
        signal(SIGURG, mySignalHandler);
        printf("%i\n", getpid());

        chdir("/");
        setsid();

        close(0);
        close(1);
        close(2);

        while (1) {
            usleep(50000);
        }
    }
}
