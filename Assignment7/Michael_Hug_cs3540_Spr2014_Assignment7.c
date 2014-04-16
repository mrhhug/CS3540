#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void err_exit (const char* message);

void report(char *fname, char *wordreport)
{
	if (strcmp(wordreport,"report") != 0)
		err_exit("Unknown keyword - do you mean 'report'?");
	if (access(fname,F_OK) !=0)
		err_exit("unable to generate report, file not found");
	if (access(fname,R_OK) !=0)
		err_exit("unable to read file, check permissions");
	int fd = open (fname, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		err_exit ("error in opening file for read");
	int result =1;
	char namebuf[15];
	char pricebuf[8];
	char countbuf[4];
	while(result>0)
	{
		read (fd,namebuf,15);
		read (fd,pricebuf,8);
		result = read (fd,countbuf,4);
		if(result>0 && strcmp(namebuf,"TOMBSTONE!@#$%") )
			printf("%s\t\t%s X\t%s =\t%f\n",namebuf,pricebuf,countbuf,atof(pricebuf)*atoi(countbuf));
	}
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
		err_exit("Unknown keyword - do you mean 'add'?");
	if (atof(price)==0.0)
		err_exit("the price can not me cast to double");
	char namebuf[15];
	if (strlen(name)<15)
		strcpy(namebuf,name);
	char pricebuf[8];
	if(strlen(price)<8)
		strcpy(pricebuf,price);
	char countbuf[4];
	if(strlen(count)<4)
		strcpy(countbuf,count);
	int fd = open(fname, O_RDWR|O_APPEND|O_CREAT,0666);
	int result = write(fd,namebuf,15);
	if (result <0)
		err_exit("could not write name to file");
	result = write(fd,price,8);
	if (result <0)
		err_exit("could not write price to file");
	result = write(fd,count,4);
	if (result <0)
		err_exit("could not write count to file");
	close(fd);
}
void delete(char *fname, char *deleteKeyword, char *name)
{
	if (strcmp(deleteKeyword,"delete") != 0)
		err_exit("Unknown keyword - do you mean 'delete'?");
	int result =1;
	char namebuf[15];
	FILE *fb = fopen(fname,"rb");
	fseek(fb, 0L, SEEK_END);
	int sz = ftell(fb);
	fseek(fb, 0L, SEEK_SET);
	fclose(fb);
	printf("%d",sz);
	int fd = open(fname, O_RDWR);
	while(result<0)
	{
		read (fd,namebuf,15);
		printf("%s",namebuf);
		if(strcmp(namebuf,name))
			write(fd,"TOMBSTONE!@#$%",15);
		result = lseek(fd,12,SEEK_CUR);
	}
}
int main(int argc, char *argv[])
{
	if(argc == 3)
		report(argv[1],argv[2]);
	else if(argc == 4)
		delete(argv[1],argv[2],argv[3]);
	else if(argc == 6)
		add(argv[1],argv[2],argv[3],argv[4],argv[5]);
	else
		err_exit("invalid number of arguments");
	return 0;
}
