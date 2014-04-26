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
#include <signal.h>

const char *fname = "counterFile.ttx";
#define maxCount 25
pid_t parentPID;
pid_t sonPID;
pid_t daughterPID;

void kill_exit();
void err_exit (const char* message);

void parentSigalarm(int signo)
{
	if(readCounter()>=maxCount)
		kill_exit();
	if(readCounter() % 2)
		kill(daughterPID,SIGALRM);
	else
		kill(sonPID,SIGALRM);
}
void childSigalarm()
{
	char *child;
	if(sonPID==0) // this means current process is son
		child="son     ";
	else
		child="daughter";
	printf("%s wrote %d to %s\n",child,incrementFile(),fname);
	kill(parentPID,SIGALRM);
}
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
	close(fd);
	return atoi(buf);
}
int addOneTotInt(int i)
{
	i++;
	return i;
}
//do not worry about writing less digits, we are only incrementing
int writeCounter(int counter)
{
	//right here is where I use the math library.
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
	return writeCounter(addOneTotInt(readCounter()));
}
int main ()
{
	printf("parent pid is %d\n",getpid());
	parentPID=getpid();
	int fd = creat (fname, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
		err_exit ("error in creating file");
	int result = write (fd, "0", 1);
	if (result != 1)
		err_exit ("write failed");
	close(fd);
	if ((sonPID = fork()) < 0)
		err_exit("fork error");
	if (sonPID==0)
	{
		printf("son created, pid %d\n",getpid());
		signal(SIGALRM,childSigalarm);
		for (;;)
		{
			pause();
		}
	}
	else
	{
		if ((daughterPID = fork()) < 0)
		{
			err_exit("fork error");
		}
		else if (daughterPID == 0) 
		{
			printf("daughter created, pid %d\n",getpid());
			signal(SIGALRM,childSigalarm);
			for (;;)
			{
				pause();
			}
		}
		else
		{
			signal(SIGALRM,parentSigalarm);
			parentPID=getpid();
		}
	}
	alarm(1);
	for(;;)
	{
		pause();
	}
	//no return 0 because the only way to exit this program is through kill_exit
}
void kill_exit()
{
	kill(daughterPID,SIGKILL);
	kill(sonPID,SIGKILL);	
	exit(0);
}
void err_exit (const char* message)
{
	printf ("%s\n", message);
	kill_exit();
}
