#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/limits.h>

int
main()
{
	char *buf;
	printf("%d\n",PATH_MAX);
	printf("%d\n",mkdir("/home/hmichae4/thing",S_IRUSR | S_IWUSR | S_IXUSR));
	printf("%s\n",getcwd(buf,0));
	chdir("/home/hmichae4/thing/");
	// everything about buf1 should be done and over with
	// buff 2 does not act right
	// but if I reuse buf1 it works fine or comment out the buf1 block
	char *buf2;
	printf("%s\n",getcwd(buf2,0));

	free(buf);
	free(buf2);

	//////the worst part is that is seems to effect my other pointers
	//
	//FILE *fp = fopen("~/LOGFILE.txt","a");
	//fprintf(fp,"%s","test");
	//fclose(fp);
	return 0;
}
