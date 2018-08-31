#include "func.h"
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args");
		return -1;
	}
	int fd;
	printf("O_RDWR=%x,O_CREAT=%x\n",O_RDWR,O_CREAT);
	fd=open(argv[1],O_RDWR|O_CREAT,0666);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	printf("fd=%d\n",fd);
	return 0;
}
