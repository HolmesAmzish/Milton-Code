#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h> // 包含 close 函数的声明

#define SERVER_PORT 5432
#define MAX_LINE 256

int main(int argc, char* argv[]) {
    struct hostent* hp;
    struct sockaddr_in sin;
    char* host;
    char buf[MAX_LINE];
    int s;
    int len;

    if (argc == 2) {
        host = argv[1];
    } else {
        fprintf(stderr, "usage: simple-talk host\n");
        exit(1);
    }

    // Translate host name into peer's IP address
    hp = gethostbyname(host);
    if (!hp) {
        fprintf(stderr, "simplex-talk: unknown host: %s\n", host);
        exit(1);
    }

    // Build address data structure
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    memcpy(&sin.sin_addr, hp->h_addr, hp->h_length);
    sin.sin_port = htons(SERVER_PORT);

    // Active open
    if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("simplex-talk: socket");
        exit(1);
    }
    if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) < 0) {
        perror("simplex-talk: connect");
        close(s);
        exit(1);
    }

    // Main loop: get and send lines of text
    while (fgets(buf, sizeof(buf), stdin)) {
        buf[MAX_LINE - 1] = '\0';
        len = strlen(buf) + 1;
        if (send(s, buf, len, 0) == -1) {
            perror("simplex-talk: send");
            close(s);
            exit(1);
        }
    }

    close(s);
    return 0;
}
