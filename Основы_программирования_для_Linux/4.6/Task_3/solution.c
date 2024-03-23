#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int signalUSR1 = 0, signalUSR2 = 0;

void mySignalHandler(int signalNum) {
    if (signalNum == SIGUSR1) {
        ++signalUSR1;
    } else if (signalNum == SIGUSR2) {
        ++signalUSR2;
    } else if (signalNum == SIGTERM) {
        printf("%i %i\n", signalUSR1, signalUSR2);
        exit(0);
    }
}

int main() {
    signal(SIGUSR1, mySignalHandler);
    signal(SIGUSR2, mySignalHandler);
    signal(SIGTERM, mySignalHandler);

    while (1) {}

    return 0;
}
