#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
int main(){

	struct sockaddr_in sock1,sock2;
	socklen_t addr_len = sizeof(sock2);
	char buffer[1024];
	
	sock1.sin_family = AF_INET;
	sock1.sin_port = htons(6532);
	sock1.sin_addr.s_addr= INADDR_ANY;

	int sockfd1;
	sockfd1=socket(PF_INET,SOCK_DGRAM,0);
	if(sockfd1 <0){
		printf("error\n");
	}
	else{
		printf("socket descriptor: %d\n",sockfd1);
	}
	
	int bind1;
	bind1= bind(sockfd1,(const struct sockaddr *)&sock1,sizeof(sock1) );
	if(bind1<0){
		printf("bind failure\n");
	}
	else{
		printf("bind successful\n");
	}
	
	printf("waiting for message\n");
	
	int bytes =recvfrom(sockfd1,buffer,1023,0,(struct sockaddr*)&sock2,&addr_len);
	if (bytes < 0) {
        printf("Failed to receive data\n");
    	} 
    	else {
        	buffer[bytes] = '\0'; 
        	printf("\nReceived %d bytes from %s:%d\n",bytes, inet_ntoa(sock2.sin_addr),ntohs(sock2.sin_port));
       	 	printf("Message: %s\n", buffer);
    	}
	close(sockfd1);
	return 0;
}
