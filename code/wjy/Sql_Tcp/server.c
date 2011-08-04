/*srver.c*/

#include <stdio.h>

#include <arpa/inet.h>

/*O_RDONLY*/
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

/*STDOUT_FILENO*/
#include <unistd.h>

/*bzero*/
#include <strings.h>

/*strlen*/
#include <string.h>

#include "trs.h"

int main(int argc, const char *argv[])
{
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    char *stat = STAT_TALK;
    //talk more than buf
    char trs_buf[MAXLINE], in_buf[MAX_ARRAY];
    int filefd;
    int opt = 1;
    
    listenfd = trs_socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SRV_PORT);

    trs_bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    trs_listen(listenfd, 20);
   
    printf("server start ...\n");
    while(1) 
    {
        cliaddr_len = sizeof(cliaddr);
        connfd = trs_accept(listenfd, (struct sockaddr *)&cliaddr\
        , &cliaddr_len);
        
        printf("%s already connect\n", inet_ntoa(cliaddr.sin_addr));

        bzero(trs_buf, MAXLINE);
        trs_read(connfd, trs_buf, MAXLINE);

        if(0 == strcmp(STAT_TALK, trs_buf)) 
        {
            while(1)
            {

                printf("he say:\n");
                bzero(trs_buf, MAXLINE);
                trs_read(connfd, trs_buf, MAXLINE);

                trs_write(STDOUT_FILENO, trs_buf, sizeof(trs_buf));
                printf("\n");
                printf("you say:\n");
                get_str(in_buf, MAX_ARRAY);
                if(0 == strcmp(QUIT, in_buf)) 
                {
                    break; 
                }

                trs_write(connfd, in_buf, strlen(in_buf));
            }
        }
        else if(0 == strcmp(STAT_FILE, trs_buf)) 
        {

            bzero(trs_buf, MAXLINE);
            trs_read(connfd, trs_buf, MAXLINE);
            printf("start create %s file ...\n", trs_buf);

            filefd = trs_open_m(trs_buf, O_RDONLY|O_CREAT|O_APPEND, 666);

            while(1) 
            {
                trs_read(connfd, trs_buf, MAXLINE);
                trs_write(filefd, trs_buf, strlen(trs_buf));
                if(strlen(trs_buf) < MAXLINE) 
                {
                    break; 
                }
            }
            printf("already get %s file\n", trs_buf);
            
        }

        trs_close(listenfd);
    }
    trs_close(connfd);
    return 0;
}
