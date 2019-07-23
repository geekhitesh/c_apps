// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 9999 
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char const *argv[]) 
{ 
	struct sockaddr_in address; 
	int sock = 0, valread,random_number=0,max=99999; 
	struct sockaddr_in serv_addr; 
	char *hello = "Hello from client"; 
        char message[256];
        char process_id[30];
        int pid=0,i=0,no_of_childs=10;	
        char buffer[1024] = {0};
        printf("tell me no. of childs");
        //scanf("%d",no_of_childs); 

        /*while(i<no_of_childs) {
           printf("condition true in while");
             if(pid==0) {
                  printf("forking <%d> child",(i+1));
                  pid = fork();
                  i++; 
             }
        }*/
        fork();
        fork();
        fork();
        fork();
        fork();
        fork();
        fork();
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 
	memset(&serv_addr, '0', sizeof(serv_addr)); 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	{ 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		printf("\nConnection Failed \n"); 
		return -1; 
	} 
        while(1) {
            random_number = rand();
            sprintf(message,"%d",random_number);
            strcat(message," is sent by process - ");
            sprintf(process_id,"%d",getpid());
            strcat(message,process_id); 
            strcat(message,"\n");  
            send(sock , message, strlen(message) , 0 );
            //sleep(10);
            printf("Message Sent: <%s>",message);
        }  
//	valread = read( sock , buffer, 1024); 
//	printf("%s\n",buffer ); 
	return 0; 
} 

