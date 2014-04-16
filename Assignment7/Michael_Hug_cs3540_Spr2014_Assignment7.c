#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void err_exit (const char* message);

int isFileReadable(const char *fname)
{
	int readable =0 ;
	if(access(fname,R_OK) !=-1)
	{
		readable =1;
	}
	return readable;
}
int isFileWritable(const char *fname)
{
	int writable = 0;
	if(access(fname,W_OK) != -1)
	{
		writable = 1;
	}
	return writable;
}
int doesFileExist(const char *fname)
{
	int exists = 0;
	if (access(fname,F_OK) != -1)
	{
		exists = 1;
	}
	return exists;
}
int createFile(const char *fname)
{
	
}
void report(char *fname, char *wordreport)
{
	if (strcmp(wordreport,"report") != 0)
		err_exit("Unknown keyword - do you mean 'report'?");
	if (access(fname,F_OK) !=0)
		err_exit("unable to generate report, file not found");
	if (access(fname,R_OK) !=0)
		err_exit("unable to read file, check permissions");
	int fd = open (fname, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	char buf[5];
	if (fd < 0)
		err_exit ("error in opening file for read");
	int result = read (fd,buf , 5);
	if (result < 0)
		err_exit ("write error");
	printf("%s",buf);
	close(fd);
}
void err_exit (const char* message)
{
	printf ("%s\n", message);
	exit(0);
}
void add(char *fname, char *addKeyword, char *name, char * price, char *count)
{
	if (strcmp(addKeyword,"add") != 0)
		err_exit("Unknown keyword - do you mean 'report'?");
	if (access(fname,R_OK) !=0)
		err_exit("unable to write file, check permissions");
	char namebuf[15];
	char pricebuf[8];
	char countbuf[4];
	FILE *fp=fopen(fname, "a");
	fprintf(fp, "%s %s %s", name, price, count);
	fclose(fp);
}
int main(int argc, char *argv[])
{
	if(argc == 3)
		report(argv[1],argv[2]);
	else if(argc == 6)
		add(argv[1],argv[2],argv[3],argv[4],argv[5]);
	else
		err_exit("invalid number of arguments");
	return 0;
}
