# Book
+Linux C编程一站式学习
    +   http://learn.akae.cn/media/index.html

+xingwenpeng@akaedu.org

+   mianshibaodian

+   9808510 

--------------------------------------------------------------------------
# in bash
+   cat
+   dash and bash

------------------------------------------------------------------
# in vim
+   z+c
+   z+v

----------------------------------------------------------------------------
# Syntax
##  char
+   have another meanning 
    char a = '\\';      T
    char a = '%%';      F
    cahr a = ''';       F

## operator
+   a&&b, a&b, ||,|,!,~

+   bitwise more efficient than operator

--------------------------------------------------------------------------------------
# program

## needn't know more aboout math, but algorithm need

## module 
+   any complex can change to easy on module

+   why statement ,it is check.

+   C function can't pass address, it  need Point

##  Incremental Development

## .c->.s->.o->ELF

------------------------------------------------------------------
# memory
+   static 
	+   local static	:		(put it in the static)
	+   global static   :	   (only in the file)
		
+   store  
	+   heap			:   malloc
	+   section		    :   global
	+   stack		    :   local,program-counter and ? 

+   variable
	+   global variable :   default initial 0
	+   local variable  :   default initial random

+   const
    +   read-only
    +   const

+   bss data ro.data text  
    char +str = "sefsdfs"; 
    char s[10]= "sefsdfs"; 
    +   str(ro.data) -> identifier -> address   

## Buffer
+   stdin, stdout, stderr
    +   include buffer

#+   stdout flush
    +   '\n'
    +   full(4096B)
    +   fflush()
    +   end

+  char str[4096] 

## copy
+   memmove();      //cross
+   strcpy();       //string
+   memcpy();
   
## ELF
+   include
    +   bss
    +   data
    +   ro.data
    +   text

## 0-4G
+   include
    +   linux
    +   Stack
    +   Shared library
    +   Heap
    +   ELF

## store at the 4 byte

-------------------------------------------------------------------------------------
# debug
+   rand
	+   man rand
	+   man 2 rand
	+   man 3 rand

+   man
    +   seven 
    +   shift + k

+   strace()
    
+   sleep();
+   usleep();
    
----------------------------------------------------------------------------------------------
# Algorithm

## Recursive

#   get another stack-space

+   waste of resources

----------------------------------------------------------------------------------------------
# value convert
+   atoi()

+   strtl()

+   strtoll()
-----------------------------------------------------------
#  string
+   printf()
    +   %p  
      	print address

+   strtok(char* s, char *token);
    +   char *p = s;

    +   p = strtok(p," ");

    +   p = strtok(NULL, " ");
        +   remind the place
        +   p = strtok(0, " ");
    
+   strcpy(char *d, char *s);  
	// s must be longer than d  
    //check

+   strcmp(char *d, char *s);
    +   ASC
    +   'a' 97 0x61
    +   'A' 0x41
    +   '0' 0x70

+   strcat();
    +   splice STRING

+   strncpy();

+   strncmp();

+   scanf()
    +   stdio.h
    +   buffer
    +   scanf("%10s", &s);
    +   scanf("%d, %d" &d1, &d2); else scanf("%d %d" &d1, &d2);
    +   C-compile meet enter,line,illegal-data,space will end;

+   perror("error message");
    +   stdlib.h

+   strcpy();
    +   char+ d[] get string
    +   sting.h

+   free(point); 

## main
+   main-return
    +   status 

+   main-argc
    +   count

+   main-argv
    +   ./main aa bb cc

## putchar
+   print only a word

## strlen
+   #include<string>
+   string length, end of '\0'

# Data structure
## link list
+   malloc must be need

----------------------------------------------------------------------------------------------
# Point
+   property
    +   mark p store adress 
    +   when the location move  
        the point is more faster than array

+   int +P = &a; 
    +   initialize

+   int b[N];
    int *p;
    int a[M][N];
    int **ptr;
    int (*pt)[M];
    int *pstr[M];
    
    p = b;
    p = &a[0][0];
    p = &b[0];
    ptr = pstr;
    pt = a;
    +   char *p;
    +   int  *p;

+   NULL
    +   macro defintion 0(Point)


+   Point to double-digit group
    +   int array[4][5];
    +   int (*s) = array;

+   char +argc[]
    +   a array

+   char ++p;   
----------------------------------------------------------------------------------------------
# struct 
## format
+   Type definition
    +  AS char 
        struct node
        {
            int num;
            char name[20];
        }

    +   no equal int + char ..
    +   struct can't include struct  
        but can include point of struct
    +   struct node 
## 
+   struct a = b; value;
---------------------------------------------------------------------------------------------
# array
## array-name
+   const point

------------------------------------------------------------------------------------------------
# library
## static library
+   gcc -c  fn.c

## Shared library
+   
    1.  gcc -fPIC -c fn.c
    2.  gcc -shared -o fn.so *.o

+   gcc main.c -I./include -L./lib -lstack 
    1.  lib ldd
    2.  export LD_LIBRARY_PATH = "  "
    3.  vim /etc/ld.so.cof  
        add path
    +   ehco $PATH
    +   env
    +   export
+   ldconfig -v  
    flush

----------------------------------------------------------------------------------------------
# equipment
+   Display <- Graphics <- filebuffer <- linux
+   ioctl();        //set or get parameters
+   fb_var_screeninfo
+   /dev/fb0
+   /dev/input/mice
    
+   mmap();         //a memory to a file
    +   MAP_SHARD
        +   same fd will get a same memory address

    +   MAP_PRIVATE 
        
+   bpp     //piexl median
+   grub.cfg        //system  start
    +   vag = 0x318;
+   

-----------------------------------------------------------------------------
# file
+   need know
    +   how to end
        +   EOF   
             EOF is a Binary so get or put shou be a char when use EOF
        +   \n
        +   0

    +   how read subscript

+   fopen(name, ways)
+   fscanf(fp, )
+   fprinf()
+   fclose()
+   fgetc()
+   getc()  
    it's use fgetc() to defined a Macro
+   putc()
+   fputc()  
    as getc and fgetc
+   gets() and fgets()
    +  	gets() don't limit the count of read  
       	but fgets limit;
    +   gets() end with \n 
    +   fgets() have \n
+   rewind()
+   fread();
+   fwrite();
+   fseek();

---------------------------------------------------
# linux file
+   open(const char *pathname, int flags, ...)
    +   return fd   //File scriptor
    +   dup2()
    +   struct file
    +   PCB
    +   task_struct -> files_struct

+   read()
    +   '\n'
    +   

+   write()
+   close()
+   fstat()

------------------------------------------------------------------------------
# Makefile
+   
    1.  Relationship tree
    2.  from the bottom leaf node

+    
    CFLAG = -Wall -c -fPIC
    LDFLAG = -shared
    libsrc = $(wildcard lib/*.c)
    obj = $(patsubst %.c, %.o, $(libsrc))
    CC = gcc
    target = libtest.so
    
    all:$(obj)
    $(CC) $(obj) $(LDFLAG) -o $(target)
    
    %.o:%.c
    $(CC) $(CFLAG) -o $@ $<
    .PHONY:clean
    clean:
    rm -f $(obj)
    rm -f $(target)


--------------------------------------------------------------------------
# Signaling mechanism
+   kill -l
+   ps -aux
+   kill -9(signal) 3826
+   signal(int signum, int (*fp)(int));
+   Callback function

-------------------------------------------------------------------------
# search
+   find
+   grep "name" ./ -R

--------------------------------------------------------------

-------------------------------------------------------------
# error
+   (<&>)
+   array border
+   .h  //location
+   mouse //return -1
+   windows to linux //lost 
+   PMOUSE pMouse;
    pMouse->start_x;
+   process runing

----------------------------------------------------------------
# data
1.  
    for (;i++,i<5;);
2.  
    
--------------------------------------------------------------
# number
## Random
+   srand(time(NULL));
+   rand();

## Number-system
+ 	length
    +   char c = 128; => -128  
        -128~127
        -127~256
+   long 
    +   machine length

### bitwise
+   mask		
+   avoid constant
+    define variables must initialization
+    `>>`
	+   unsigned int >> add 0 
	+   int >> add 1

+   8 and 4 needn't macro definiton

### type switch
+   int to char

+   conversion
	int c ;
	float f;
	printf("%f,%d",c,f);

+   float compare 
	+   can't use "=" should use ">=" "<="

+   simple to complex

+   sign and unsign
	+   to unsign
+   portability need habit

+   hardware knowledge

+   array_traversal  
	+   cache  one by one to read

-------------------------------------------------------------
# permissions
+   unmask
    +   unmask 0022
+   chmod
+     

----------------------------------------------------------------
# system
+   tty()         //Terminal
+   task_struct, files_struct
+   stdin, stdout, stderr

## Process
+   fork()
+   exec()
    +   p:  path
    +   l:  argument
    +   v:  argument array
    +   e:  path array

+   wait()
+   waitpid()
+   exit()

### pipe
+   pipe()
+   `mkfifo hello`

## thread
+   gcc -lpthread
+   pthread_create()
+   exit
    +   return
    +   pthread_exit()
    +   pthread_cancel()
+   pthread_join()

### thread syn
+   pthread_mutex_lock()
+   pthread_mutex_unlock()
+   pthread_mutex_trylock();
+   pthread_mutex_init();


----------------------------------------------------------------
# show
+   od -tx1 -tc
+   vim
+   cat
    +   cat > 2.txt     //cat 1>2.txt
    +   cat < 1.txt     //cat 0>1.txt
    +   cat 2>2.txt
+   dd if=src.c of=dst.c bs=54 skip=1 
--------------------------------------------------------------
# Redirect 
+   >,<,>>,<>
    +   cat  2>temp.txt
    +   cat  >tmp.txt
# ctr+z fg
