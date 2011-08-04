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
#include "inet.h"
#include <sys/stat.h>
#include <fcntl.h>

#define MAXLINE 4*1024
#define SERV_PORT 8000

int main(int argc, const char *argv[])
{
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i, n, m;
    int fd;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (char*)opt, sizeof(opt));

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    
    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    Listen(listenfd, 20);

    printf("Accepting connections ...\n");
    while(1) 
    {
        cliaddr_len = sizeof(cliaddr);
        connfd = accept(listenfd,\
        (struct sockaddr *)&cliaddr, &cliaddr_len);
        m = fork();
        
        if(-1 == m) 
        {
            perr_exit("call tp fork");
        }
        else if(0 == m)
        {
            Close(listenfd); 
            while(1)
            {
                //n = Read(connfd, buf, MAXLINE); 
                //if(0 == n) 
                //{
                //break; 
                //}

                //printf("received from %s at PORT %d\n",inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),ntohs(cliaddr.sin_port));

                //for(i = 0; i < n; i++) 
                //{
                    //buf[i] = toupper(buf[i]);
                //}
                //Write(connfd, buf, n);
                
                n = Read(connfd, buf, MAXLINE); 
                if(0 == n) 
                {
                    break; 
                }
                printf("%s\n",buf);
                if(strcmp(buf,TRS_FILE_ST)) 
                {
                    printf("STRAT\n");
                    fd = open("2.txt",  O_RDWR|O_CREAT, 0666);      
                    n = Read(connfd, buf, MAXLINE); 
                    if(0 == n) 
                    {
                        break; 
                        printf("sd\n");
                    }
                    printf("%s\n",buf);
                    Write(fd, buf, n);
                    //Write(connfd, buf, MAXLINE);
                }
                else if(strcmp(buf, TRS_FILE))
                {
                    printf("ON\n");
                    n = Read(connfd, buf, MAXLINE); 
                    if(0 == n) 
                    {
                        break; 
                    }
                    else if(MAXLINE != n) 
                    {
                       perr_exit("TRS_FILE read"); 
                    }
                    //Write(connfd, buf, MAXLINE);
                }
                else if(strcmp(buf, TRS_FILE_END))
                {
                    n = Read(connfd, buf, MAXLINE); 
                    if(0 == n) 
                    {
                        break; 
                    }
                    //Write(connfd, buf,n);
                }

                
            }
            Close(connfd);
            exit(0);
        }
        Close(connfd);
    }
    return 0;
}
