#include "func.h"
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args");
		return -1;
	}
	int fd;
	//O_TRUNC如果文件已经存在，就将它截取为0
	fd=open(argv[1],O_RDWR|O_TRUNC,0666);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	printf("fd=%d\n",fd);
	return 0;
}
