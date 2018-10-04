#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main(){

char msg[1024] = "close to the metal";

int ss ;

ss = socket(AF_INET,SOCK_STREAM,0);

//define address

struct sockaddr_in server;

server.sin_family = AF_INET;
server.sin_port = htons(4444);

server.sin_addr.s_addr = INADDR_ANY;

//bind to port

bind(ss,(struct sockaddr *) &server,sizeof(server));

//listen

listen(ss,4); // 4 is the max number of connections

printf("Listening ...\n");

int acceptofcon ;

acceptofcon = accept(ss,NULL,NULL);

send(acceptofcon , msg, sizeof(msg),0);

close(ss);


return 0;

}