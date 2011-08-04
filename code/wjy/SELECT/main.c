#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i, maxi, maxfd, listenfd, conned, sockfd;
    int nready, client[FD_SETSIZE];
    ssize_t n;
    fd_set rset, allset;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    socklen_t cliaddr_len;
    struct sockaddr_in cliaddr, servaddr;

    listenfd = Socket(AF_INET, SOCKSTREAM, 0);

    return 0;
}
