#include"sys/socket.h"
#include"stdio.h"
#include"netinet/in.h"
#include"netinet/ip.h"
#include"string.h"
#include"arpa/inet.h"
 #include"unistd.h"
int main(){
	struct sockaddr_in sock1,sock2;
	sock1.sin_family = AF_INET;
	sock1.sin_port = htons(5010);
	sock1.sin_addr.s_addr = INADDR_ANY;
	
	int sockfd;
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd <0){
		printf("error\n");
	}
	else{
		printf("socket descriptor: %d\n",sockfd);
	}
	
	int bindfd;
	bindfd= bind(sockfd,(const struct sockaddr *)&sock1,sizeof(sock1) );
	if(bindfd<0){
		printf("bind failure\n");
	}
	else{
		printf("bind successful\n");
	}
	
	sock2.sin_family = AF_INET;
	sock2.sin_port = htons(6532);
	sock2.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	char *msg = "Hello from Client." ;
    	int sent= sendto(sockfd, msg, strlen(msg), 0,(const struct sockaddr *)&sock2, sizeof(sock2));
	if (sent < 0) {
        	printf("Failed to send message\n");
    	} else {
        	printf("Successfully sent %d bytes to port 6532\n", sent);
    	}
    	
	close(sockfd);
	
    	return 0;
}

