#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
//功能：访问给定目录中的所有文件，打印输出
void printdir(char* path,int width)
{
	char buf[512];
	memset(buf,0,sizeof(buf));
	DIR *dir;
	dir=opendir(path);
	struct dirent *p;
	while((p=readdir(dir))!=NULL)
	{
		if(!strcmp(p->d_name,".")||!strcmp(p->d_name,".."))
		{
		}else
		{
			printf("%*s%s\n",width,"",p->d_name);
			if(p->d_type==4) //如果是目录的话
			{
				sprintf(buf,"%s%s%s",path,"/",p->d_name);
				printdir(buf,width+4);
			}
		}
	}
}
int main(int argc,char* argv[])	
{
	if(argc!=2)
	{
		printf("error args");
		return -1;
	}
	printdir(argv[1],0);
	printf("%s\n",argv[1]);
	return 0;
}
