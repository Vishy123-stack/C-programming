#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet/ip.h>
#include<netinet/in.h>
#include<sys/socket.h>

int main(int argc, char *argv[])
{
    int sockfd1, sockfd2;
    int child;
    struct sockaddr_in server, client;
    socklen_t len_client;
    char buffer[1024];

    if(argc != 2)
    {
        printf("enter the port number please\n");
        return 1;
    }

    sockfd1 = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd1 < 0)
    {
        printf("error in creating socket\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    server.sin_addr.s_addr = INADDR_ANY;

    int bindfd = bind(sockfd1,(struct sockaddr *)&server,sizeof(server));

    if(bindfd < 0)
    {
        printf("error in binding\n");
        return 1;
    }

    int listening = listen(sockfd1, 5);

    if(listening < 0)
    {
        printf("failed to listen\n");
        return 1;
    }

    printf("the server is waiting for clients...\n");

    while(1)
    {
        len_client = sizeof(client);

        sockfd2 = accept(sockfd1,(struct sockaddr *)&client,&len_client);

        if(sockfd2 < 0)
        {
            printf("failed to accept\n");
            continue;
        }

        printf("client connection successful\n");

        child = fork();

        if(child == 0)
        {
            close(sockfd1);

            while(1)
            {
                int rec = recv(sockfd2,buffer,sizeof(buffer) - 1,0);

                if(rec <= 0)
                {
                    printf("client disconnected\n");
                    break;
                }

                buffer[rec] = '\0';

                printf("client: %s\n", buffer);

                if(strcmp(buffer, "logout") == 0)
                {
                    printf("the client has logged out\n");
                    break;
                }

                printf("server: ");
                fgets(buffer, sizeof(buffer), stdin);

                send(sockfd2,buffer,strlen(buffer) + 1, 0);
            }

            close(sockfd2);
            return 0;
        }
        else{
            close(sockfd2);
        }
    }

    close(sockfd1);

    return 0;
}
