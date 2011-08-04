/* server.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <arpa/inet.h>
#include "inet_error.h"

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, const char *argv[])
{
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int sockfd;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i, n;

    sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    printf("Accepting connections ...\n");
    while(1) 
    {
        cliaddr_len = sizeof(cliaddr);
        n = recvfrom(sockfd, buf, MAXLINE, 0
        , (struct sockaddr *)&cliaddr, &cliaddr_len);
        if(-1 == n) 
        {
            perr_exit("recvfrom error");
        }
        printf("received from %s at PORT %d\n"
        , inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str))
        , ntohs(cliaddr.sin_port));

        for(i = 0; i < n; i++) 
        {
            buf[i] = toupper(buf[i]);
        }
        n = sendto(sockfd, buf, n, 0
        , (struct sockaddr *)&cliaddr, sizeof(cliaddr));
        
        if(-1 == n) 
        {
            perr_exit("sendto error");
        }
    }
    return 0;
}
