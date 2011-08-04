/* client.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include "inet_error.h"

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, const char *argv[])
{
    struct sockaddr_in servaddr, cliaddr;

    int sockfd, n;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    char *ipstr = "127.0.0.1";
    socklen_t servaddr_len;

    sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, ipstr, &servaddr.sin_addr);

    servaddr.sin_port = htons(SERV_PORT);

    while(fgets(buf, MAXLINE, stdin) != NULL) 
    {
        printf("%s\n", buf);
        n = sendto(sockfd, buf, strlen(buf), 0
                , (struct sockaddr *)&servaddr, sizeof(servaddr));
        if(-1 == n) 
        {
            perr_exit("sendto error");
        }

        n = recvfrom(sockfd, buf, MAXLINE, 0, NULL, 0);
        if(-1 == n) 
        {
            perr_exit("recvfrom error");
        }
        Write(STDOUT_FILENO, buf, n);
    }

    close(sockfd);
    return 0;
}
