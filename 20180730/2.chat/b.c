#include "func.h"
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args");
		return -1;
	}
	int fd;
	fd=open(argv[1],O_RDONLY);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	printf("I am pipe O_RDONLY\n");
	char buf[128];
	int ret;
	while(1)
	{
		memset(buf,0,sizeof(buf));
		ret=read(fd,buf,sizeof(buf));//将字符串读入buf中
		printf("%s\n",buf);
	}
	return 0;
}
