#include "unp.h"
int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVE_PORT);
    servaddr.sin_addr.s_addr = inet_addr(SERVE_IP);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        err_sys("connect error");
    }

    str_cli(stdin, sockfd);
}