#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int args_count, char** args) {
    if (args_count != 2) return 1;

    int portNum = atoi(args[1]);
    struct sockaddr_in local;

    if (!portNum) return 2;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    local.sin_family = AF_INET;
    local.sin_port = htons(portNum);
    inet_aton("127.0.0.1", &local.sin_addr);

    int result = bind(sock, (struct sockaddr*)&local, sizeof(local));
    char buffer[BUFSIZ];

    while (true) {
        ssize_t length = read(sock, buffer, BUFSIZ);
        buffer[length] = '\0';

        if (strcmp(buffer, "OFF\n") == 0) break;
        printf("%s\n", buffer);
    }
}
