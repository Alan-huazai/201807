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
	printf("fd=%d\n",fd);
	char buf[128];
	memset(buf,0,sizeof(buf));
	int ret;
	ret=read(fd,buf,sizeof(buf));
	if(-1==ret)
	{
		perror("read");
		return -1;
	}
	printf("ret=%d,buf=%s\n",ret,buf);
	close(fd);
	return 0;
}
