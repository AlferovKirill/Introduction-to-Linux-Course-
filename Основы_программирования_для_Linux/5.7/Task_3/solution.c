#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <stdbool.h>

void swap(char* x, char* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(char* arr, int n) {
    bool swapped;

    for (char i = 0; i < n - 1; ++i) {
        swapped = false;

        for (char j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) break;
    }
}

void server(int port) {
    struct sockaddr_in addr;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    int client_sock;

    inet_aton("127.0.0.1", &addr.sin_addr);
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;

    bind(sock, (struct sockaddr*)&addr, sizeof(addr));
    listen(sock, 5);

    client_sock = accept(sock, NULL, NULL);

    while (true) {
        char buffer[BUFSIZ];
        ssize_t length = read(client_sock, buffer, BUFSIZ);

        if (strncmp(buffer, "OFF", 3) == 0) break;

        bubbleSort(buffer, length);
        send(client_sock, buffer, length, 0);
    }

    close(client_sock);
    close(sock);
}

int main(int arg_count, char** args) {
    if (arg_count != 2) exit(1);
    else server(atoi(args[1]));

    return 0;
}
