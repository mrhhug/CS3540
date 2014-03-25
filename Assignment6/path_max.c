#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <linux/limits.h>
#include <string.h>

int
main()
{
	char big[8356999] = "";
	printf("%s%d\n","the size of a char is ",sizeof(char));
	printf("%s%d\n","the size of a int is ",sizeof(int));
//	char big[8377000] = ""; this is about 8 megabytes. and it works sometimes. 
	char *buf = NULL;
	printf("%d\n",INT_MAX);
	
	printf("%s\n",getcwd(NULL,0));

	printf("%s\n",buf[0]);
	strcat(big,getcwd(buf,0));
	printf("\n new buf %s",big);
	printf("%d\n",mkdir(buf,S_IRUSR | S_IWUSR | S_IXUSR));
	chdir("/home/hmichae4/thing/");
	buf = NULL;
	printf("%s\n",getcwd(buf,0));

	free(buf);

	//////the worst part is that is seems to effect my other pointers
	//
	//FILE *fp = fopen("~/LOGFILE.txt","a");
	//fprintf(fp,"%s","test");
	//fclose(fp);
	return 0;
}
