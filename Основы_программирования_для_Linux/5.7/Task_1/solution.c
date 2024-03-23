#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int args_count, char** args) {
    if (args_count != 2) return 1;

    struct hostent* h = gethostbyname(args[1]);
    if (h == NULL) return 2;

    for (int i = 0; h->h_addr_list[i] != NULL; ++i) {
        printf("%s\n", inet_ntoa(*((struct in_addr*)h->h_addr_list[i])));
    }
}
