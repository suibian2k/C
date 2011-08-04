/*trs.h*/

#ifndef _TRS_H_
#define _TRS_H_


#define QUIT "quit"
#define STAT_TALK "stat_talk"
#define STAT_FILE "stat_file"
#define MAXLINE 80
#define SRV_PORT 8000
#define MAX_ARRAY 4096
#define SRV_IP "127.0.0.1"


/*trs_error.c*/
void trs_error_exit(const char *s);
int trs_socket(int domain, int type, int protocol);
int trs_bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
int trs_inet_pton(int af, const char *src, void *dst);
int trs_listen(int sockfd, int backlog);
int trs_connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
int trs_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
ssize_t trs_read(int fd, void *buf, size_t count);
ssize_t trs_write(int fd, void *buf, size_t count);
int trs_open(const char *pathname, int flags);
int trs_open_m(const char *pathname, int flags, mode_t mode);
void trs_close(int fd);

/*use.c*/
void flush_stdin(void);
char *get_str(char *str, int len);
#endif
