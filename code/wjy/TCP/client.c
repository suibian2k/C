/* ckuent.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "inet_error.h"
#include "inet.h"

#define MAXLINE 80
#define SERV_PORT 8000
#define MAX_TRS_BYTE 4*1024

int main(int argc, const char *argv[])
{
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    char *str;
    char *fn = "1.txt";
    char ts[4096];
    char *ipstr = "127.0.0.1";
    
    int nSendBuf = MAX_TRS_BYTE;

    int sockfd, n, i;
    int fd;


    str = (char *)argv[1];

    sockfd = Socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(sockfd,SOL_SOCKET,SO_SNDBUF,(const char*)&nSendBuf,sizeof(int));


    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, ipstr, &servaddr.sin_addr);
    servaddr.sin_port = htons(SERV_PORT);
    Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    int count;
    char rf[MAX_TRS_BYTE];

    char *trs_type = TRS_FILE_ST;
    while(1) 
    {
        /* Initialization*/
        i = 0;
        memset(ts, 0, 4096);
        memset(buf, 0, MAXLINE);

        /* get a string*/
        //printf("Need a string\n");
        //ts[i] = fgetc(stdin); 
        //while('\n' != ts[i])
        //{
            //i++;
            //ts[i] = fgetc(stdin); 
        //}

        //if(0 == i) 
        //{
            //continue; 
        //}

        //write(sockfd, ts, i);
        while(1) 
        {
            fd = open(fn, O_RDONLY);

            write(sockfd, trs_type, strlen(trs_type));

            count = read(fd, rf, MAX_TRS_BYTE);
            printf("%s\n",trs_type);
            if(-1 == count) 
            {
                perr_exit("read fd"); 
            }
            else if(count <= MAX_TRS_BYTE) 
            {
                trs_type = TRS_FILE_END;
                getchar();
                printf("11\n");
                write(sockfd, rf, count);
                break;
            }
            else
            {
                trs_type = TRS_FILE;
            }
            write(sockfd, rf, count);

        }


        //n = Read(sockfd, buf, MAXLINE); 
        //printf("Response from server:\n");
        //Write(STDOUT_FILENO, buf, n);
        //printf("\n");
        sleep(2);
        break;
    }

    Close(sockfd);
    return 0;
}
