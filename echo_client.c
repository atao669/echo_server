#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 666
#define SERVER_IP "127.0.0.1"

int main(int argc, char *argv[]){
	
	int sockfd;
	char *message;
	// socket地址
	struct sockaddr_in servaddr;
	int n;
	char buf[64];

	if(argc != 2){
		fputs("Usage: ./echo_client message \n", stderr);
		exit(1);
	}
	message = argv[1];
	printf("Client prepares to send a message: %s\n", message);


	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	
	// servaddr清零
	memset(&servaddr, '\0', sizeof(struct sockaddr_in));
	
	// 设置sockaddr
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, SERVER_IP, &servaddr.sin_addr);
	servaddr.sin_port = htons(SERVER_PORT);
	
	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	write(sockfd, message, strlen(message));

	n = read(sockfd, buf, sizeof(buf)-1);
	
	if(n > 0){
		buf[n] = '\0';
		printf("Client receives: %s\n", buf);
	}else{
		perror("Client error !");
	}

	printf("Client finished. \n");

	close(sockfd);
	return 0;

}





