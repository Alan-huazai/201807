#include <string.h>
#include <stdio.h>
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args");
		return -1;
	}
	char buf[128];
	memset(buf,0,sizeof(buf));
	FILE *fp;
	fp=fopen(argv[1],"rb+");
	if(NULL==fp)
	{
		perror("fopen");
		return -1;
	}
	long off;
	fseek(fp,5,SEEK_SET);
	off=ftell(fp);
	printf("off=%ld\n",off);
	return 0;
}
