#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t ntid;

void printids(const char *s);
void *thr_fn(void *arg);

int main(int argc, const char *argv[])
{
    int err;    
    
    // a new thread
    err = pthread_create(&ntid, NULL, thr_fn, "new thread:");
    if(err!=0) 
    {
       fprintf(stderr,"can't create thread %s\n", strerror(err)); 
    }
    //printids("main thread:");
    
    printf("I will control frame\n");
    sleep(1);
    return 0;
}

// 
void printids(const char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid, (unsigned int )tid, (unsigned int)tid); 

}

// a thread run funtion
void *thr_fn(void *arg)
{
    printf("I will control mouse\n");
    //printids(arg);
    return NULL;
}

