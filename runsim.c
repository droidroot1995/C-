#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

int count = 0;

int isNum(char * str){
	int i =0;
	while(str[i] != '\0' && isdigit((int)str[i++]));
	if (str[i] == '\0' && isdigit(str[i - 1])) return 1;
	return 0;
}

void handler(int sig)
{
	if(SIGCHLD == sig) count--;
}
int main(int argc, char * argv[])
{
	if(argc < 2 || !isNum(argv[1]))
	{
		printf("Too few arguments!!!\n");
		return 1;
	}
	signal(SIGCHLD, handler);
	int n = atoi(argv[1]);
	char str[256];
	while(gets(str))
	{		
		if(count == n)
		{
			printf("Too much processes\n");
			continue;
		}
		int p =fork();
		switch(p)
		{
			case -1:
				printf("Can't create process!!!\n");
				exit(-1);
				break;
			case 0:
				execlp(str,str,NULL);
				break;
			default:
				count++;
				break;
		}

	}
	printf("End of File!!!\n");
	
	return 0;
}
