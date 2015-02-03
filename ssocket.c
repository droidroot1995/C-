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
	char line[1000];
	struct sockaddr_in servaddr, clientaddr;
	bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		servaddr.sin_port = htons(51000);
		servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	sockfd = socket(PF_INET, SOCK_DGRAM, 0);
	bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	while(1)
	{
		int clilen = sizeof(clientaddr);
		recvfrom(sockfd, line, 999, 0, &clientaddr, &clilen);
		printf("%s\n",line);
		sendto(sockfd, line, strlen(line), 0, &clientaddr, clilen);
	}
	return 0;
}