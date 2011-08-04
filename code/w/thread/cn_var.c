#include <stdio.h>
#include <pthread.h>    
#include <stdlib.h>
#include <unistd.h>

struct msg 
{
    struct msg *next;
    int num;
};

struct msg *head;
pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *consumer(void *p)
{
    struct msg *mp;
    //struct msg *lp;

    while(1)
    {
        pthread_mutex_lock(&lock);
        printf("%d\n",lock);
        while(NULL == head) 
        {
            pthread_cond_wait(&has_product,&lock); 
        }

        //mp = head;
        //while(mp->next!=NULL) 
        //{
            //lp = mp;
            //mp = mp->next; 
        //}
        //lp->next = NULL;

        mp = head;
        head = mp->next;
        pthread_mutex_unlock(&lock);
        printf("Consume %d\n", mp->num);
        free(mp);
        sleep(rand()%5);
    }

}
void *producer(void *p)
{
    struct msg *mp;
    struct msg *hp;
    while(1) 
    {

        mp = malloc(sizeof(struct msg));
        mp->num = rand()%1000+1;
        printf("Produce %d\n",mp->num);
        pthread_mutex_lock(&lock);
        if(NULL == head) 
        {
           head = mp; 
           head->next = NULL;
        }
        else
        {
            hp = head;
            while(NULL != hp->next) 
            {
              hp = hp->next;  
            }

            hp->next = mp;
            mp->next = NULL;
        }
        //mp->next = head;
        //head = mp;
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&has_product);
        sleep(rand()%5);
    }

}

int main(int argc, const char *argv[])
{
    pthread_t pid,cid;
    srand(time(NULL));
    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);
    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
    return 0;
}
