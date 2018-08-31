#include "func.h"
int main(int argc,char* argv[])
{
	if(argc!=3)
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
	long file_size=atol(argv[2]);
	int ret;
	ret=ftruncate(fd,file_size);
	if(-1==ret)
	{
		perror("ftruncte");
		return -1;
	}
	return 0;
}
