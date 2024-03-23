#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if (pid != 0) {
        return 0;
    } else {
        printf("%i\n", getpid());

        chdir("/");
        setsid();

        close(stdout);
        close(stdin);
        close(stderr);

        while (1) {
            usleep(50000);
        }
    }
}
