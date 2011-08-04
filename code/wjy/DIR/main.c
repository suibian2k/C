#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int my_read_dir(const char arg[])
{
    DIR *my_dir;
    struct dirent dir;

    my_dir = opendir(arg)
    if(-1 = ret)
    {
        printf("opendir error\n");
        return -1;
    }
    while((dir = readdir(my_dir)) != NULL) 
    {
        printf("fiel name:%s\n", dir->d_name);
    }
    closedir(my_dir);
    return 0;
}
int main(int argc, const char *argv[])
{
    struct stat buf; 

    if(argc<2) 
    {
        printf("usage: %s para\n", _FILE_);
        exit(-2);
    }
    
    /*file message*/
    stat(argv[1], &buf);

    if(!S_ISDIR(buf, st_mode)) 
    {
        printf("diretory not found\n");
        exit(3);
    }

    if(my_read_dir(argv[1]) < 0) 
    {
       exit(-1); 
    }
    return 0;
}
