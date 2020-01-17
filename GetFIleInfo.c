#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

static int i = 1 ;

void GetTotalFile(char *path)
{

  DIR *dfp = opendir(path);

  struct dirent *file;

  struct stat FileInf;

  while((file=readdir(dfp))!=NULL)
{
   if(strcmp(file->d_name,".")==0||strcmp(file->d_name,"..")==0)
	continue;
   
  char TotalPath[256]={0};

   strcat(TotalPath,path);
   
   strcat(TotalPath,file->d_name);
  
   if(stat(TotalPath,&FileInf)>=0)
   {
	if(S_ISDIR(FileInf.st_mode))
           {
 		strcat(TotalPath,"/");
 		GetTotalFile(TotalPath);
           }
    
    printf("path=%s\n",TotalPath);

   printf("%d file name=%s\n",i,file->d_name);
	  
     printf("%d file st_ino=%d\n",i,FileInf.st_ino);

     printf("\n\n\n");

     i++;
 }
   else
    {
	printf("stat get failure\n");

    }
}
   closedir(dfp);

}

int main(int argc,char **argv)
{

     if(argc!=2)
{
     printf("path error");
}   
  
	GetTotalFile(argv[1]);

	return 0;
}

