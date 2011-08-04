/*trs_error.c*/

/*socket*/
#include <sys/types.h>
#include <sys/socket.h>

/*errno*/
#include <errno.h>

/*open*/
#include <sys/stat.h>
#include <fcntl.h>

/*read*/
#include <unistd.h>

/*exit*/
#include <stdlib.h>



void trs_error_exit(const char *s)
{
    perror(s); 
    exit(1);
}

int trs_socket(int domain, int type, int protocol)
{
    int ret;
    while(1) 
    {
        ret = socket(domain, type, protocol);
        if(-1 == ret) 
        {
            if(EINTR == errno) 
            {
                continue;  
            }
            else
            {
                trs_error_exit("socket error");
            }
        }
        return ret;
    }
}

int trs_bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen)
{
    int ret;
    while(1) 
    {
        ret = bind(sockfd, addr, addrlen);
        if(-1 == ret) 
        {
            if(EINTR == errno) 
            {
                continue;  
            }
            else
            {
                trs_error_exit("bind error");
            }
        }
        return ret;
    }
}

int trs_inet_pton(int af, const char *src, void *dst)
{
    int ret;
    while(1) 
    {
        ret = inet_pton(af, src, dst);
        if(-1 == ret) 
        {
            if(EINTR == errno) 
            {
                continue;  
            }
            else
            {
                trs_error_exit("inet_pton error");
            }
        }
        if(0 == ret) 
        {
            trs_error_exit("inet_pton error ip:");
        }
        return ret;
    }
}
int trs_listen(int sockfd, int backlog)
{
    int ret;
    while(1) 
    {
        ret = listen(sockfd, backlog);
        if(-1 == ret) 
        {
            if(EINTR == errno) 
            {
                continue;  
            }
            else
            {
                trs_error_exit("listen error");
            }
        }
        return ret;
    }
}

int trs_connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen)
{
    int n;
    while(1) 
    {
        n = connect(sockfd, addr, addrlen);
        if(-1 == n) 
        {
            if(EINTR == errno) 
            {
                continue;  
            }
            else
            {
                trs_error_exit("connect error");
            }
        }
        return n;
    }
}
int trs_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int n;
    while(1) 
    {
        n = accept(sockfd, addr, addrlen);
        if(-1 == n) 
        {
            if((EINTR == errno)||(ECONNABORTED == errno))
            {
                continue;  
            }
            else
            {
                trs_error_exit("accept error");
            }
        }
        return n;
    }
}
ssize_t trs_read(int fd, void *buf, size_t count)
{
    ssize_t n ;
    while(1) 
    {
        n = read(fd, buf, count);
        if(-1 == n) 
        {
            if(EINTR == errno) 
            {
                continue;  
            }
            else
            {
                trs_error_exit("read error");
            }
        }
        return n;
    }
}
ssize_t trs_write(int fd, void *buf, size_t count)
{
    ssize_t n ;
    while(1) 
    {
        n = write(fd, buf, count);
        if(-1 == n) 
        {
            if(EINTR == errno) 
            {
                continue;  
            }
            else
            {
                trs_error_exit("write error");
            }
        }
        return n;
    }
}

int trs_open(const char *pathname, int flags)
{
    int ret ;
    while(1) 
    {
        ret = open(pathname, flags);
        if(-1 == ret)
        {
            if(EINTR == errno) 
            {
                continue;  
            }
            else
            {
                trs_error_exit("open error");
            }
        }
        return ret;
    }
}

int trs_open_m(const char *pathname, int flags, mode_t mode)
{
    int ret ;
    while(1) 
    {
        ret = open(pathname, flags, mode);
        if(-1 == ret)
        {
            if(EINTR == errno) 
            {
                continue;  
            }
            else
            {
                trs_error_exit("open error");
            }
        }
        return ret;
    }
}

void trs_close(int fd)
{
    if(-1 == close(fd)) 
    {
       trs_error_exit("close error"); 
    }
}
