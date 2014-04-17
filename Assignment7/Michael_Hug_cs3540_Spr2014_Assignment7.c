/*
 *Author : Michael Hug
 *Author email : hmichae4@students.kennesaw.edu
 *Student of Prof Gayler cs3540 Spr014
 *Assignment 7
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/***********************************************
precondition:
wordreport is the char * "report"
fname is a a file that can be read from

prints all non-deleted entries
postcondition:
*/
void report(char *fname, char *wordreport);
/***********************************************
precondition:
addKeyword is the char * "add"
fname is a a file that can be wrote from

postcondition:
new records are added to the file
*/
void add(char *fname, char *addKeyword, char *name, char * price, char *count);
/***********************************************
precondition:
deleteKeyword is the char * "delete"
fname is a a file that can read/write to 

postcondition:
if record is in datafile, the record is marked as deleted
*/
void delete(char *fname, char *deleteKeyword, char *name);
int getFileSize(char *fname);
void err_exit (const char* message);

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
	double total =0;
	while(result>0)
	{
		read (fd,namebuf,15);
		read (fd,pricebuf,8);
		result = read (fd,countbuf,4);
		if(result>0 && strcmp(namebuf,"TOMBSTONE!@#$%t") != 0 )
		{
			double sum = atof(pricebuf)*atoi(countbuf);
			printf("%s\t\t%s X\t%s =\t%g\n",namebuf,pricebuf,countbuf,sum);
			total+=sum;
		}
	}
	printf("\t\tTotal\t  =\t%g\n",total);
	close(fd);
}
void add(char *fname, char *addKeyword, char *name, char * price, char *count)
{
	if (strcmp(addKeyword,"add") != 0)
		err_exit("Unknown keyword - do you mean 'add'?");
	if (atof(price)==0.0)
		err_exit("the price can not cast to double");
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
	int iterations = getFileSize(fname)/(15+8+4);	
	int fd = open(fname, O_RDWR);
	while(iterations--)
	{
		read (fd,namebuf,15);
		if(strcmp(namebuf,name)==0)
		{
			lseek(fd,-15,SEEK_CUR);
			write(fd,"TOMBSTONE!@#$%t",15);
		}
		result = lseek(fd,12,SEEK_CUR);
	}
}
int getFileSize(char *fname)
{
	FILE *fb = fopen(fname,"rb");
	fseek(fb, 0L, SEEK_END);
	int sz = ftell(fb);
	fseek(fb, 0L, SEEK_SET);
	fclose(fb);
	return sz;
}
void err_exit (const char* message)
{
	printf ("%s\n", message);
	exit(0);
}
