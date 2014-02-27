#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void err_exit (const char* message);

int main ()
{
	int fd1 = open ("gbu", O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd1 < 0)
		err_exit ("error in opening file");
	char buf [1];
	int numbytes = 0;
	int size = 0;
	do
	{
		size = read (fd1, buf, 1);
		if (size < 0)
			err_exit ("read error");
		else
			numbytes += size;
	}
	while (size);
	//numbytes--; //eof or something
	
	int fd2 = creat ("copy.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd2 < 0)
		err_exit ("error in creating file");
		
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

void err_exit (const char* message)
{
	printf ("%s\n", message);
	exit(0);
}
