/*
 *Author : Michael Hug
 *Author email : hmichae4@students.kennesaw.edu
 *Student of Prof Gayler cs3540 Spr014
 *Assignment 5
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void err_exit (const char* message);
int file_size(char* fileName);

int main ()
{
	//char* inputFile = "nonew.txt"; // for testing
	char* inputFile = "gbu.txt";
	char* outputFile = "copy.txt";
	int numbytes = file_size(inputFile);
	int fd1 = open (inputFile, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd1 < 0)
		err_exit ("error in opening file for read");
	int fd2 = creat (outputFile, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd2 < 0)
		err_exit ("error in creating file for write");
	char buf [1];	
	while(numbytes--)
	{
		int result = lseek (fd1, numbytes, SEEK_SET);
		if (result < 0)
			err_exit ("error in seek");
		result = read (fd1, buf, 1);
		if (result < 0)
			err_exit ("read error");
		result = write (fd2, buf, 1);
		if (result < 0)
			err_exit ("write error");
	}
	close (fd1);
	close (fd2);
	return 0;
}

int file_size(char* fileName)
{
	int buffSize = 10;
	int fd1 = open (fileName, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd1 < 0)
		err_exit ("error in opening file for count");
	char buf [buffSize];
	int numbytes = 0;
	int size = 0;
	do
	{
		size = read (fd1, buf, buffSize);
		if (size < 0)
			err_exit ("read error in count");
		else
			numbytes += size;
	}
	while (size);
	close (fd1);
	return numbytes;
}

void err_exit (const char* message)
{
	printf ("%s\n", message);
	exit(0);
}
