#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>



int main(int argc,char *argv[])
{
	char buf[1024];
	int fdin,fdout;
	ssize_t nread,nwrite;
	int file_del_retal;
	int rtn;

// original file open for read mode

	fdin=open(argv[1],O_RDONLY);
	if(fdin==-1)
	{
	printf("fopen() failed, %s not found\n",argv[1]);
	}
	

	fdout=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fdout==-1)
	{
	printf("fopen() filed,%s not found \n",argv[2]);
	exit(1);
	}

//	rename(argv[1],argv[2]);	

	nread=read(fdin,buf,100);
	nwrite=write(fdout,buf,nread);
	
	rtn=unlink(argv[1]);

	}

	



