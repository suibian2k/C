#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
    int number;
    char name[20];
    struct node *next;
};

typedef struct node V_NODE;

V_NODE *add_link(V_NODE *head);
V_NODE *delete_link(V_NODE *head);
V_NODE *creat_link(int n);
void print_link(V_NODE *head);
void print_list();
void save_link(V_NODE *p);
int  get_choice();
V_NODE *load_link(void);
int main(int argc, const char *argv[])
{

    V_NODE *head = NULL;
    head = load_link();
    char flag = 0;
    while(!flag)
    {
        print_list();
        switch(get_choice())
        {
            case 1: 
                head = add_link(head);
                break;
            case 2:
                head = delete_link(head);
                break;
            case 3: 
                print_link(head);
                break;
            case 4:
                flag = 1; 
                break;
            default:
                break;

        }
    }

    save_link(head);
    return 0;
}

V_NODE *add_link(V_NODE *head)
{
    V_NODE *p = NULL;
    V_NODE *ptr = head;

    if (NULL == head) 
    {
        p = malloc(sizeof(V_NODE));
        head = p;
        printf("number\n");
        scanf("%d", &p->number);

        printf("name\n");
        scanf("%s", p->name);

        p->next = NULL;
        return p;
    }

    p = malloc(sizeof(V_NODE));

    if (NULL == p) 
    {
        perror("malloc");
        exit(0);
    }

    printf("number\n");
    scanf("%d", &p->number);

    printf("name\n");
    scanf("%s", p->name);

    p->next = NULL;

    if (p->number < ptr->number) 
    {
        p->next = ptr;
        return p;
    }

    while ((ptr->next != NULL)&&(p->number > ptr->next->number)) 
    {
        ptr = ptr->next;
    }

    if (NULL == ptr->next) 
    {
        ptr->next = p;
        return head;
    }

    p->next = ptr->next;
    ptr->next = p;
    return head;
}

V_NODE *delete_link(V_NODE *head)
{
    V_NODE *ptr = head;
    V_NODE *p = NULL;

    int num = 0;
    if (NULL == head) 
    {
        printf("null\n");
        return NULL;
    }

    printf("delete num\n");
    scanf("%d", &num);
    if (num == head->number) 
    {
        printf("already delete\n");
        return NULL;
    }

    while ((NULL != ptr->next)&&(num != ptr->next->number)) 
    {
        ptr = ptr->next;
    }

    if (NULL == ptr->next) 
    {
        printf("no have\n");
        return head;
    }

    p = ptr->next;
    ptr->next = ptr->next->next;
    free(p);
    printf("already delete\n");
    return head;
}

V_NODE *creat_link(int n)
{
    V_NODE * head = NULL;
    int i = 0;

    if (n < 1) 
    {
        return NULL; 
    }

    head = add_link(NULL);
    for (i = 1; i < n; i++) 
    {
        head = add_link(NULL);
    }
    return head;
}
void print_link(V_NODE *head)
{
    while (NULL != head) 
    {
        printf("number = %d  name = %s\n", head->number, head->name);
        head = head->next;
    }    
}

V_NODE *load_link(void)
{
    FILE *fp = NULL;
    V_NODE *head = NULL;
    V_NODE *p = NULL;
    int num = 0;
    char na[20];

    fp = fopen("text1", "r+");

    if (NULL == fp) 
    {
        perror("fopen");
        exit(0);
    }

    if (fscanf(fp,"%d%s", &num, na) != EOF) 
    {
        p = malloc(sizeof(V_NODE));
        if (NULL == p) 
        {

            perror("malloc");
            exit(0);
        }
        p->number = num;
        strcpy(p->name, na);
        p->next = NULL;
        head = p;
    }

    while((d = fscanf(fp,"%d%s", &num, na)) != EOF) 
    {
        p->next = malloc(sizeof(V_NODE));
        if (NULL == p->next) 
        {

            perror("malloc");
            exit(0);
        }
        p->next->number = num;
        strcpy(p->next->name, na);
        p->next->next = NULL;
    }
    fclose(fp);
    return head;

}

void save_link(V_NODE *p)
{
    FILE *fp = NULL;

    fp = fopen("text1", "w+");

    if (NULL == fp) 
    {
        perror("fopen");
        exit(0);
    }

    while (NULL != p) 
    {
        fprintf(fp, "%d\t%s\n", p->number, p->name);
        p = p->next;
    }
    fclose(fp);

}
void print_list()
{
    printf("list\n");
    printf("1.add\n");
    printf("2.delete\n");
    printf("3.print\n");
    printf("4.exit\n");
}
int get_choice()
{  
    char choice[20];
    scanf("%s", choice);
    return atoi(choice);
}
