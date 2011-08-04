#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <errno.h>

void perr_exit(const char *s)
{
    perror(s);
    exit(1);
}

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
    int n;

    while((n = accept(fd, sa, salenptr) < 0))
    {
        if((ECONNABORTED == errno)||(EINTR == errno)) 
        {
            continue;
        }
        else
        {
            perr_exit("accept error");
        }
    }

    return n;
}

void Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
    if(bind(fd, sa, salen) < 0) 
    {
        perr_exit("bind error");
    }
}

void Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
    if(connect(fd, sa, salen) < 0) 
    {
       perr_exit("connect error"); 
    }
}

void Listen(int fd, int backlog)
{
    if(listen(fd, backlog) < 0) 
    {
        perr_exit("listen error"); 
    }
}

int Socket(int family, int type, int protocol)
{
   int n;

   if((n = socket(family, type, protocol)) < 0) 
   {
      perr_exit("socket error"); 
   }

   return n;
}

ssize_t Read(int fd, void *ptr, size_t nbytes)
{
    ssize_t n;
    while(-1 == (n = read(fd, ptr, nbytes)))
    {
        if(EINTR == errno)
        {
            continue;
        }
        else
        {
            return -1;
        }
    }
    return n;
}
ssize_t Write(int fd, const void *ptr, size_t nbytes)
{
    ssize_t n;

    while(-1 == (n = write(fd, ptr, nbytes)))
    {
        if(EINTR == errno)
        {
            continue;
        }
        else
        {
            return -1;
        }
    }
    return n;
}

void Close(int fd)
{
    if(-1 == close(fd)) 
    {
       perr_exit("close error"); 
    }
}
