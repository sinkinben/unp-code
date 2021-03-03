#include "unp.h"
int main(int argc, char *argv[])
{
    int i, sockfd[5];
    struct sockaddr_in servaddr;

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVE_PORT);
    servaddr.sin_addr.s_addr = inet_addr(SERVE_IP);

    for (i = 0; i < 5; i++)
    {
        sockfd[i] = socket(AF_INET, SOCK_STREAM, 0);
        connect(sockfd[i], (struct sockaddr *)&servaddr, sizeof(servaddr));
    }
    str_cli(stdin, sockfd[0]);
}