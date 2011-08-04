/*client.c*/

#include <stdio.h>

/*STDOUT_FILENO*/
#include <unistd.h>
/*open*/
#include <sys/stat.h>
#include <fcntl.h>
/**/
#include <arpa/inet.h>
/*bzero*/
#include <strings.h>
/*strlen*/
#include <string.h>
#include "trs.h"


int print_menu()
{
   printf("1.talk\n");
   printf("2.file\n");
   return getchar();
}

int main(int argc, const char *argv[])
{
    struct sockaddr_in servaddr;
    int sockfd, filefd;
    int n;
    char trs_buf[MAXLINE], in_buf[MAX_ARRAY];
    char *stat = STAT_TALK;
    char slct;

    sockfd = trs_socket(AF_INET, SOCK_STREAM, 0);
    
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    trs_inet_pton(AF_INET, SRV_IP, &servaddr.sin_addr);
    servaddr.sin_port = htons(SRV_PORT);

    while(1) 
    {
        slct = print_menu();
        flush_stdin();
        trs_connect(sockfd, (struct sockaddr *)&servaddr\
                , sizeof(servaddr));
        switch(slct)
        {
            case '1':
                stat = STAT_TALK;
                trs_write(sockfd, stat, strlen(stat));
                while(1) 
                {
                    printf("you say:\n");

                    get_str(in_buf, MAX_ARRAY);

                    if(0 == strcmp(QUIT, in_buf)) 
                    {
                       break; 
                    }
                    trs_write(sockfd, in_buf, strlen(in_buf));
                        
                    //突然断
                    printf("he say:\n");

                    bzero(trs_buf, MAXLINE);
                    trs_read(sockfd, trs_buf, MAXLINE);
                    trs_write(STDOUT_FILENO, trs_buf, strlen(trs_buf));
                    printf("\n");
                }
                break;
            case '2':
                stat = STAT_FILE;
                trs_write(sockfd, stat, strlen(stat));

                printf("which file:please input file name\n");

                get_str(in_buf, MAX_ARRAY);
                if(0 == strcmp(QUIT, in_buf)) 
                {
                    break; 
                }
                
                //读脏数据
                trs_write(sockfd, in_buf, strlen(in_buf));

                filefd = trs_open(in_buf, O_RDONLY);
                //while(1) 
                //{
                bzero(trs_buf, MAXLINE);
                trs_read(filefd, trs_buf, MAXLINE);
                getchar();
                    
                trs_write(sockfd, trs_buf, strlen(trs_buf));
                //if(strlen(trs_buf) < MAXLINE) 
                //{
                    //break; 
                //}
                //}
                break;
            default:
                break;
        }
    }
    trs_close(sockfd);
    return 0;
}

