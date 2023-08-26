#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<stdio.h>

void error(const char *msg){
  perror(msg);
  exit(1);
}

int main(int argc, char* argv[])
{
int sockfd,newsockfd,port_number,n;
  if(argc<2)
  {
    fprintf(stderr,"PORT NUMBER NOT GIVEN\n");
    exit(1);
   }

char buffer[255];
struct sockaddr_in serv_addr, client_addr;
socklen_t clientLength;

sockfd = socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0){
  error("ERROR OPENING SOCKET\n");
}
bzero((char*)&serv_addr,sizeof(serv_addr));
//clears the buffer
port_number = atoi(argv[1]);//argv[0] contains filename, argv[1] contains port_number

serv_addr.sin_family =  


}



