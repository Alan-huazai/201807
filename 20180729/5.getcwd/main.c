#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(int argc,char* argv[])
//int main()
{
	if(argc!=2)
	{
		printf("error args");
		return -1;
	}
	char buf[128];
	memset(buf,0,sizeof(buf));
//	char *p=getcwd(buf,sizeof(buf));
//	printf("%s\n",p);
//	puts(p);
	printf("%s\n",getcwd(NULL,0));
	chdir(argv[1]);
	printf("%s\n",getcwd(NULL,0));
	FILE *fp;
	fp=fopen("file","rb+");
	if(NULL==fp)
	{
		perror("open");
		return -1;
	}
	return 0;
}
