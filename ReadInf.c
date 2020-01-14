#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

int main()
{
	FILE *fp;

	fp = fopen("conf.txt","r");

	
	if(fp==NULL)
	{
		printf("open file failure\n");
		return -1;
	}	

	
	char buf[MAXSIZE];
	char IP[MAXSIZE];
	char port[10];
	int  PORT;
	
	while(fgets(buf,MAXSIZE,fp))
{
	if(strstr(buf,"IP="))
	sscanf(buf+3,"%[^\n]",IP);

	if(strstr(buf,"PORT="))
	sscanf(buf+5,"%[^\n]",port);
}
	PORT = atoi(port);

	printf("ip=%s\n",IP);
	
	printf("port=%d\n",PORT);
	
	fclose(fp);
	
	return 0;
}



