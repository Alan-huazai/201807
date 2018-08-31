#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args");
		return -1;
	}
	struct stat buf;
	memset(&buf,0,sizeof(buf));
	int ret;
	ret=stat(argv[1],&buf);		//	获取文件信息
	if(-1==ret)
	{
		perror("stat");
		return -1;
	}
	printf("st_nio=%ld st_mode=%x ",buf.st_ino,buf.st_mode);
	printf("st_nlink=%ld ",buf.st_nlink);
	printf("st_uid=%s ",getpwuid(buf.st_uid)->pw_name);
	printf("st_uid=%s ",getgrgid(buf.st_gid)->gr_name);
	printf("st_size=%ld ",buf.st_size);
	printf("st_mtime=%s\n",ctime(&buf.st_mtime));
	return 0;
}
