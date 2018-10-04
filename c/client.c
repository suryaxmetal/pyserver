#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){

/* creating socket */

int network_s ;

network_s = socket(AF_INET,SOCK_STREAM,0);

// specify and address for the socket

struct sockaddr_in server_address;

server_address.sin_family = AF_INET;

server_address.sin_port = htons(4444);

server_address.sin_addr.s_addr = INADDR_ANY;

int status = connect(network_s,(struct sockaddr *) &server_address,sizeof(server_address));

//error-handling

if(status == -1){

printf("Failed to establish connection");

}

//receive data from server

char data[1024];

recv(network_s, &data,sizeof(data),0);

printf("RECEIVED : %s",data);

close(network_s);

}
