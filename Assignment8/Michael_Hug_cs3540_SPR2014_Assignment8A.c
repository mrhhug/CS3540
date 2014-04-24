/*
 *Author : Michael Hug
 *Author email : hmichae4@students.kennesaw.edu
 *Student of Prof Gayler cs3540 Spr014
 *Assignment 8 - Write a program that creates a zombie, and then call system to execute the ps(1) command
to verify that the process is a zombie. 
 */
  
#include <stdio.h>
#include <stdlib.h>

void err_sys (const char* message);

int main ()
{
	pid_t pid;
	if ((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid == 0) //child
	{
		printf("The child PID : %d\n", getpid());
		exit(0);
	}
	if (pid>0)
	{
		printf("The parent PID : %d\n", getpid());
		sleep(1); // depending on system speed, alter the sleep time
		system("ps");
	}
	return 0; 
}
void err_sys (const char* message)
{
	printf ("%s\n", message);
	exit (0);
}
