#include<stdio.h>

int main(char *srcPath,char *dstPath)
{
	int retVal;
	int len=0;
	char szTemp[512];
	char buff[4096];
	FILE *in_fp,*out_fp;
	size_t n_size; // value of data for read or write

	//original file open for read mode

	in_fp=fopen(srcPath,"r");
	if(in_fp==NULL)
	{
		printf("fopne()..failed,srcPath=(%s) not found\n",srcPath);
		return -1;
	}

	//target file open for write mode
	out_fp=fopen(dstPath,"w");
	if(out_fp==NULL)
	{
		printf("fopen()...failed,dstPath=(%s) not found\n",dstPath);
return -1;
	}

	//original file copy for target file
	while(0<(n_size=fread(buff,1,sizeof(buff),in_fp)))
	{
		fwrite(buff,1,n_size,out_fp);
	}

	// fp close
	fclose(in_fp);
	fclose(out_fp);

	len+=sprintf(szTemp,"File Move Success.\n");
	len+=sprintf(&szTemp[len]," - srcPath = (%s)\n",srcPath);
	len+=sprintf(&szTemp[len]," - dstPath = (%s)\n",dstPath);
	printf("%s",szTemp);

	// remove copy file
	if(retVal==-1)
	{
		printf("unlink()...failed,retVal=%d\n",retVal);
		return -1;
	}

	return 0;
}

