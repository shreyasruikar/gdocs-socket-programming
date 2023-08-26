#include<stdio.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>

int main(){
    //creating a socket
    int network_socket;
    //SOCK_STREAM = tcp
    //AF_INET for ipv4
    network_socket = socket(AF_INET,SOCK_STREAM,0);

    //specifying address for socket to connect to
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9000);
    server_address.sin_addr.s_addr = INADDR_ANY;


    int connect_status = connect(network_socket,(struct sockaddr*)&server_address,sizeof(server_address));
    //check for error with the connection
    if(connect_status==-1){
        printf("there was an error connecting to the server");
    }

    //receive data from server
    char server_response[256];
    recv(network_socket,&server_response,sizeof(server_response),0);
    printf("data from server:%s\n",server_response);

    close(network_socket);
    return 0;
}