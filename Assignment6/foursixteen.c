#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

/*
 * precondition : none
 * postcondition : new dir created in pwd named y. pwd is now car* of newly created dir
 * returns: void
 */
void createDirFact(char *pwd, int i)  
{
        //printf("%s\n",pwd);
        strcat(pwd,"/y/");
        //printf("%s",pwd);
        int status = mkdir(pwd,S_IRUSR | S_IWUSR | S_IXUSR);    
        if(status)
        {   
                printf("FAIL at %d",i);
                exit(1);
        }   
}
int main()
{
        //printf("%d\n",PATH_MAX);
        int buf_size = 5000000;
        char *pwd=malloc(sizeof(char)*buf_size);
        getcwd(pwd,buf_size);
        int i;
        for(i=0;i<4097;i++)
        {
                createDirFact(pwd,i);
        }
        free(pwd);
       	return 0;
}
/*
Does the UNIX System have a fundamental limitation on the depth of a directory tree?
To find out, write a program that creates a directory and then changes to that directory, in a loop.
Make certain that the length of the absolute pathname of the leaf of this directory is greater than your system's PATH_MAX limit.
Can you call getcwd to fetch the directory's pathname? How do the standard UNIX System tools deal with this long pathname?
Can you archive the directory using either tar or cpio?

/*
 * After testing this code and playing with it (notably the length of the new directory).
 * That there is no (kernel imposed)limit on the depth of a directory tree.
 * (the ext4 filesystem also does not impose a limit)
 * My program started to fail at X depths. After my program halted
 * I was able to CD into the directory and then run my program again
 * but it ran fewer iterations. I kept running it until it started to arbitrarily fail,
 * Then i ran mkdir from the shell(of the deep directory) and it succeeded!
 * mkdir from the shell continued to succeed for several tests. 
 
 * The kernel does not have an inherent limit to the depth of a directory tree
 * tar also does not respect PATH_MAX, but according to my tests and this documentation:
 * http://www.gnu.org/software/tar/manual/html_section/Formats.html
 * some older versions did have a limitation.
 * I have included a tared archive in the submission.
 *
 * I believe that my program was failing due to efficiency reasons.
 * C does not seem to respect PATH_MAX, but it does work more efficiently
 * in smaller lengths.
 * attached is a typescript in the submission
 * 
 */
