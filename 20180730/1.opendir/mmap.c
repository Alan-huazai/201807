#include "func.h"
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args");
		return -1;
	}
	int fd;
	fd=open(argv[1],O_RDWR|O_CREAT,0666);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	char *pstart;
	pstart=(char*)mmap(NULL,4096,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if((char*)-1==pstart)
	{
		perror("mmap");
		return -1;
	}
	printf("%s\n",pstart);
	pstart[0]='P';
	int ret=munmap(pstart,4096);
	if(-1==ret)
	{
		perror("munmap");
		return -1;
	}
	return 0;
}
