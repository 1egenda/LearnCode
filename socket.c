#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<ctype.h>


#define IP "192.168.84.85"
#define PORT 1025


int main()
{
	int sfd;
	int cfd;
	int nread;
	char buf[BUFSIZ];

	struct sockaddr_in addr;
	struct sockaddr_in caddr;

	socklen_t len;
	
	sfd = socket(AF_INET,SOCK_STREAM,0);
     
  	memset(&addr,0,sizeof(addr));
   
	addr.sin_family = AF_INET;

	addr.sin_port = htons(PORT);

	addr.sin_addr.s_addr = inet_addr(IP);

	bind(sfd,(struct sockaddr*)&addr,sizeof(addr));
	
  	listen(sfd,10);

	len = sizeof(socklen_t);


	cfd = accept(sfd,(struct sockaddr*)&caddr,&len);
       
        while(1){
	int i = 0;  
	memset(buf,0,sizeof(buf));

	nread = read(cfd,buf,sizeof(buf));
	
	for(;i<nread;i++)
		buf[i] = toupper(buf[i]);
	
	write(cfd,buf,nread);
	
          }
	close(sfd);
	close(cfd);  
	return 0;
}
