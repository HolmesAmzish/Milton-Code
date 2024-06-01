#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> // 包含 close 函数的声明

#define SERVER_PORT 5432
#define MAX_PENDING 5
#define MAX_LINE 256

int main() {
    struct sockaddr_in sin;
    char buf[MAX_LINE];
    int buf_len, addr_len;
    int s, new_s;

    // Build address data structure
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(SERVER_PORT);

    // Setup passive open
    if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("simplex-talk: socket");
        exit(1);
    }
    if ((bind(s, (struct sockaddr*)&sin, sizeof(sin))) < 0) {
        perror("simplex-talk: bind");
        close(s);
        exit(1);
    }
    if (listen(s, MAX_PENDING) < 0) {
        perror("simplex-talk: listen");
        close(s);
        exit(1);
    }

    // Wait for connection, then receive and print text
    while (1) {
        addr_len = sizeof(sin);
        if ((new_s = accept(s, (struct sockaddr*)&sin, (socklen_t*)&addr_len)) < 0) {
            perror("simplex-talk: accept");
            close(s);
            exit(1);
        }
        while ((buf_len = recv(new_s, buf, sizeof(buf), 0)) > 0) {
            fputs(buf, stdout);
        }
        close(new_s);
    }

    close(s);
    return 0;
}
