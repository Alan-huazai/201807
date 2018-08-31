#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args");
		return -1;
	}
	int ret;
//	ret=mkdir(argv[1],0777);
	ret=rmdir(argv[1]);
	printf("ret=%d\n",ret);
	return 0;
}
