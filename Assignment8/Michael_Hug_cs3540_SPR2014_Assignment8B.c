/*
 *Author : Michael Hug
 *Author email : hmichae4@students.kennesaw.edu
 *Student of Prof Gayler cs3540 Spr014
 *Assignment 8 - Write the following program to test the parent–child synchronization functions in
 Figure 10.24. The process creates a file and writes the integer 0 to the file. The process then
 calls fork, and the parent and child alternate incrementing the counter in the file. Each
 time the counter is incremented, print which process (parent or child) is doing the
 increment.
 */
  
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <semaphore.h>

const char *fname = "counterFile.ttx";
sem_t mutex;

void err_exit (const char* message);

int getFileSize()
{
	FILE *fb = fopen(fname,"rb");
	fseek(fb, 0L, SEEK_END);
	int sz = ftell(fb);
	fseek(fb, 0L, SEEK_SET);
	fclose(fb);
	return sz;
}
int readCounter()
{
	int lengthOfInt = getFileSize(fname);
	char buf[lengthOfInt];
	FILE *fb = fopen(fname,"rb");
	int fd = open (fname, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		err_exit ("error in opening file for read");
	read (fd,buf,lengthOfInt);
	return atoi(buf);
	close(fd);
}
int addOneTotInt(int i)
{
	i++;
	return i;
}
//do not worry about writing less digits, we are only incramenting
int writeCounter(int counter)
{
	int lengthOfCounter = floor (log10 (abs (counter))) + 1;
	char buf[lengthOfCounter];
	sprintf(buf, "%d", counter);
	int fd = open(fname, O_RDWR);
	if (fd < 0)
		err_exit ("error in opening file for write");
	int result = write(fd,buf,lengthOfCounter);
	if (result <0)
		err_exit("could not write counter to file");
	close(fd);
	return counter;
}
int incrementFile()
{
	writeCounter(addOneTotInt(readCounter()));
}
int main ()
{
	int fd = creat (fname, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		err_exit ("error in creating file");
	int result = write (fd, "0", 1);
	if (result != 1)
		err_exit ("write failed");
	close(fd);
	sem_init(&mutex, 0, 1);
	pid_t pid;
	if ((pid = fork()) < 0)
		err_exit("fork error");
	else if (pid == 0) //child
	{
		int i;
		for(i=0;i<20;i++)
			printf("child process wrote : \t%d\n",incrementFile());
	}
	if (pid>0) //parent
	{
		int j;
		for(j=0;j<20;j++)
		{
			printf("parent process wrote : \t%d\n",incrementFile());
		}
	}
	return 0; 
}
void err_exit (const char* message)
{
	printf ("%s\n", message);
	exit (0);
}
