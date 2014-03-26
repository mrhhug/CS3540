#include <stdio.h>
#include <linux/limits.h>
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
