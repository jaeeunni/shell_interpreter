#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>

int mymkdir(int argc,char **argv)
{


	if(argc!=2)
	{
		fprintf(stderr,"Usage : mymkdir dirname\n");
		return 1;
	}

	else
	{
		mkdir(argv[1],0755);
	}
//	if(mkdir(argv[1],0755))			
//	{
//		perror("mkdir error");
//		return 1;
//	}

	return 0;

}


