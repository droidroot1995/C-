#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>

int i= 0;

void * handler(int sig)
{
	if(i < 5)
	{
		printf("\nHahaha ^__^\n");
		i++;
	}
	else
	{
		printf("\nExit :(\n");
		i++;
		exit(1);
	}
}
int main(int argc, char * argv[])
{
	signal(SIGINT, handler);
	while(1)
	{		
		sleep(1);
	}
	return 0;
}
