#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 1024

int main(int argc,char **argv)
{

	if(argc<2)
	{
		printf("argc < 2\n");
		return 0;
	}

	char buff[MAXSIZE] = {0};

	FILE *Rfp = fopen(argv[1],"r");
	FILE *Wfp = fopen(argv[2],"w+");

	while(fgets(buff,MAXSIZE,Rfp)!=NULL)
{
	printf("%s\n",buff);
	fputs(buff,Wfp);
	memset(buff,0,MAXSIZE);
}
	fclose(Rfp);
	fclose(Wfp);	


	return 0;
}
