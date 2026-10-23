#include "sys/socket.h"
#include "stdio.h"
int main(){
	int sockfd1;
	int sockfd2;
	int sockfd3;
	sockfd1=socket(PF_INET,SOCK_DGRAM,0);
	sockfd2=socket(PF_INET,SOCK_DGRAM,0);
	sockfd3=socket(PF_INET,SOCK_DGRAM,0);
	if(sockfd1 <0 && sockfd2<0)
		printf("error\n");
	else
		printf("socket descriptor: %d\n",sockfd1);
		printf("socket descriptor: %d\n",sockfd2);
		printf("socket descriptor: %d\n",sockfd3);
	return 0;
}

