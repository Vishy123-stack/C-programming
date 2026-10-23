#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

# define N 10

int find_second_largest_number(int arr[],int n){
	int largest,secondlargest;
	if(arr[0]>arr[1]){
		largest=arr[0];
		secondlargest=arr[1];
	}
	else{
		largest = arr[1];
		secondlargest=arr[0];
	}
	for(int i = 2;i < n;i++){
		if(arr[i]>largest){
			secondlargest = largest;
			largest = arr[i];
		}
		else if(arr[i]>secondlargest && arr[i]!=largest){
			secondlargest = arr[i];
		}
	}
	return secondlargest;	
}
	
int main(){
	
	int num[N];
	int secondlargest;

	struct sockaddr_in sock1,sock2;
	socklen_t addr_len = sizeof(sock2);
	
	sock1.sin_family = AF_INET;
	sock1.sin_port = htons(6969);
	sock1.sin_addr.s_addr= INADDR_ANY;
	
	int sockfd1=socket(PF_INET,SOCK_DGRAM,0);
	if(sockfd1 <0){
		printf("error\n");
	}
	else{
		printf("socket descriptor: %d\n",sockfd1);
	}
	
	int bind1= bind(sockfd1,(const struct sockaddr *)&sock1,sizeof(sock1) );
	if(bind1<0){
		printf("bind failure\n");
	}
	else{
		printf("bind successful\n");
	}
	
	printf("waiting for 10 integers\n");
	
	int bytes =recvfrom(sockfd1,num,sizeof(num),0,(struct sockaddr*)&sock2,&addr_len);
	if (bytes < 0) {
        printf("Failed to receive data\n");
    	} 
    	else {
        	printf("\nReceived %d bytes from %s:%d\n",bytes, inet_ntoa(sock2.sin_addr),ntohs(sock2.sin_port));
       	 	printf("recieved numbers:/n");
       	 	for(int i =0;i<N;i++){
       	 		printf("%d",num[i]);
       	 	}
       	 	printf("\n");
       	 	
       	 	secondlargest = find_second_largest_number(num,N);
       	 	printf("the second largest number : %d\n",secondlargest);
       	 	int sent= sendto(sockfd1, &secondlargest, sizeof(secondlargest), 0,(const struct sockaddr *)&sock2, addr_len);
		if (sent < 0) {
        		printf("Failed to send message\n");
    		} else {
        		printf("Successfully sent %d bytes to port %d\n", sent,ntohs(sock1.sin_port));
    		}
       	 	
    	}
    	
	close(sockfd1);
	return 0;
}
