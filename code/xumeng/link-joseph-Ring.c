#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node *next;
};

typedef struct node V_NODE;
V_NODE  *init_link(int n);
void print_link(V_NODE *p,int  n);
V_NODE *joseph_link(V_NODE *p);

int main(int argc, const char *argv[])
{   
    V_NODE *head = NULL;
    V_NODE *rear = NULL;
    int n = 10;
    rear = init_link(10);
    head = rear->next;
    joseph_link(rear);
    //print_link(head, n); 

    return 0;
}

V_NODE  *init_link(int n)
{
    V_NODE *head = NULL;
    V_NODE *p = NULL;
    int i = 0;

    if (n <= 0) 
    {
        return NULL;
    }
    head = p = malloc((sizeof(V_NODE)));
    p->number = 1;
    p->next = NULL;

    if (NULL == p) 
    {
        perror("malloc");
        exit(0);
    }

    for (i = 1; i < n; i++) 
    {
        p->next = malloc(sizeof(V_NODE));
        if (NULL == p->next) 
        {
            perror("malloc");
            exit(0);
        }

        p->next->number = i+1;
        p->next->next = NULL;
        p = p->next;

    }

    p->next = head;
    return p;


}

void  print_link(V_NODE *p, int n)
{
    int i = 0;

    for (i = 0; i < n; i++) 
    {
        printf("%6d", p->number);
        if (0 == (i+1)%7) 
        {
            printf("\n");
        }
        p = p->next;

    }

    printf("\n");
}

V_NODE *joseph_link(V_NODE *p)
{
    V_NODE *ptr = p->next;
    int count = 0;
    int interval = 3;

    printf("%dserval\n",p->number);
    scanf("%d", &interval);

    if ((interval < 1)&&(NULL == p->next)) 
    {
        return p;
    }
    
    while (1) 
    {

        /* for (i = 0; i < m-2; i++) 
           {
           p = p->next;
           if (p == p->next) 
           {
           return p;
           }

           }
           printf("%d\n", p->next->number);
           ptr = p->next;
           p->next = p->next->next;
           free(ptr);
           p = p->next;
           */

        count++;
        if (count == interval) 
        {
            count = 0;
            printf("%6d->out\n", ptr->number);
            p->next = ptr->next;
            free(ptr);
            ptr = p->next;
        }
        else
        {
            p = p->next;
            ptr = p->next;
        }
        if (p == p->next) 
        {
            return p;
        }


    }

}
