#include"sys/socket.h"
#include"stdio.h"
#include"netinet/in.h"
#include"netinet/ip.h"
#include"string.h"
#include"arpa/inet.h"
#include"unistd.h"

#define N 10

int main(){

	int num[N];
	int secondlargest;
	
	struct sockaddr_in sock1,sock2;
	
	sock1.sin_family = AF_INET;
	sock1.sin_port = htons(5065);
	sock1.sin_addr.s_addr = INADDR_ANY;
	
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd <0){
		printf("error\n");
	}
	else{
		printf("socket descriptor: %d\n",sockfd);
	}

	int bindfd= bind(sockfd,(const struct sockaddr *)&sock1,sizeof(sock1) );
	if(bindfd<0){
		printf("bind failure\n");
	}
	else{
		printf("bind successful\n");
	}
	
	sock2.sin_family = AF_INET;
	sock2.sin_port = htons(6969);
	sock2.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	printf("enter 10 numbers:\n");
	for(int i =0 ; i<N; i++){
		scanf("%d",&num[i]);
	}
	
    	int sent= sendto(sockfd, num, sizeof(num), 0,(const struct sockaddr *)&sock2, sizeof(sock2));
	if (sent < 0) {
        	printf("Failed to send message\n");
    	} else {
        	printf("Successfully sent %d bytes to port %d\n", sent,ntohs(sock2.sin_port));
    	}
    	
    	int addr_len = sizeof(sock2);
    	int bytes =recvfrom(sockfd,&secondlargest,sizeof(secondlargest),0,(struct sockaddr*)&sock2,&addr_len);
	if (bytes < 0) {
        printf("Failed to receive data\n");
    	} 
    	else {
        	printf("\nReceived %d bytes from %s:%d\n",bytes, inet_ntoa(sock2.sin_addr),ntohs(sock2.sin_port));
       	 	printf("second largest number : %d\n",secondlargest);
    	}
    	
	close(sockfd);
	
    	return 0;
}

