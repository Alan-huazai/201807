#include "func.h"
int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("error args");
		return -1;
	}
	int fdw,fdr;
	fdw=open(argv[1],O_WRONLY);
	if(-1==fdw)
	{
		perror("open");
		return -1;
	}
	fdr=open(argv[2],O_RDONLY);
	if(-1==fdr)
	{
		perror("open");
		return -1;
	}
	printf("I am A\n");
	char buf[128];
	int ret;
	fd_set rdset;
	while(1)
	{
		FD_ZERO(&rdset);
		FD_SET(0,&rdset);
		FD_SET(fdr,&rdset);
		ret=select(fdr+1,&rdset,NULL,NULL,NULL);
		if(ret>0)
		{
			if(FD_ISSET(0,&rdset))
			{
				memset(buf,0,sizeof(buf));
				ret=read(0,buf,sizeof(buf));//将字符串读入buf中
				//也就是管道文件中去
				if(0==ret)
				{
					printf("byebye\n");
					close(fdr);
					close(fdw);
					break;
				}
				write(fdw,buf,strlen(buf)-1);//将buf中读入fd所指代的文件中去
			}
			if(FD_ISSET(fdr,&rdset))
			{
				memset(buf,0,sizeof(buf));
				ret=read(fdr,buf,sizeof(buf));
				if(0==ret)
				{
					printf("byebye\n");
					close(fdr);
					close(fdw);
					break;
				}
				printf("%s\n",buf);
			}
		}
	}
	return 0;
}
