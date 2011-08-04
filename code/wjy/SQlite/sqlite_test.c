#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int rscallback(void *p, int argc, char **argv, char **argvv)
{
    int i;
    *(int *)p = 0;
    for(i = 0; i < argc; i++) 
    {
        printf("%s = %s\t",argvv[i],argv[i]?argv[i]:"NULL");
    }
    putchar('\n');
    return 0;

}

int main(int argc, const char *argv[])
{
    sqlite3 *db;
    char *err = 0;
    int ret = 0;
    int empty = 1;
    char sqlstr;

    ret = sqlite3_open("./test.db", &db);

    if(SQLITE_OK != ret) 
    {
       fputs(sqlite3_errmsg(db),stderr); 

       fputs("\n",stderr);
       exit(1);
    }

    sqlstr = "select * from employee";

    ret = sqlite3_exec(db, sqlstr, rscallback, &empty, &err);

    if(SQLITE_OK != ret) 
    {
       fputs(err,stderr); 
       fputs("\n",stderr);
       sqlite3_close(db);
       exit(1);
    }

    sqlite3_close(db);
    return 0;
}
