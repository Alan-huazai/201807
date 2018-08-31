#include "func.h"
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args");
		return -1;
	}
	int fd;
	fd=open(argv[1],O_WRONLY);
	if(-1==fd)
	{
		perror("open");
		return -1;
	}
	printf("I am pipe O_WRONLY\n");
	char buf[128];
	int ret;
	while(1)
	{
		memset(buf,0,sizeof(buf));
		ret=read(0,buf,sizeof(buf));//将字符串读入buf中
		write(fd,buf,strlen(buf)-1);//将buf中读入fd所指代的文件中去
		//也就是管道文件中去
	}
	return 0;
}
