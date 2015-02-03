//#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
	int p = fork();
	if(p > 0)
	{
		//system("konsole");
		execlp("ls","ls","-l", NULL);
		_Exit(EXIT_SUCCESS);
	}
	else if(p == 0)
	{
		//system("xterm");
		execlp("ls","ls","-l", NULL);
		printf("In child\n pid: %d\n", getpid());
		_Exit(EXIT_SUCCESS);
	}
	else
	{
		//system("xtrem");
		execlp("ls","ls","-l", NULL);
		printf("Process not created\n pid: %d\n", getpid());
	}
	_Exit(EXIT_SUCCESS);
	return 0;
}
