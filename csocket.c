#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>


int main()
{
	int sockfd;
	char line[1000] = {'p','i','n','g', '\0'};

	struct sockaddr_in servaddr, clientaddr;
	bzero(&clientaddr, sizeof(clientaddr));
		clientaddr.sin_family = AF_INET;
		clientaddr.sin_port = htons(0);
		clientaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	sockfd = socket(PF_INET, SOCK_DGRAM, 0);
	bind(sockfd, &clientaddr, sizeof(clientaddr));
	
	bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(51000);
		inet_aton("127.0.0.1", &servaddr.sin_addr);
	sendto(sockfd, line, strlen(line)+1, 0, (struct sockaddr *) &servaddr, sizeof(servaddr));
	recvfrom(sockfd, line, 1000, 0, NULL, NULL);
	printf("%s\n",line);
	return 0;
} 
