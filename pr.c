#include <unistd.h>
#include <stdio.h>
int main(int argc, char* argv[])
{
	int p = fork();
	int i;
	//char argv2[];
	/*for(i = 0; i < argc; i++)
	{
		argv2[i]=argv[i+2];*/	
	if(p > 0)
	{
		if(argc > 2)
		{
			execvp(argv[1], argv+2);
		}
		else if(argc == 2)
		{
			execlp(argv[1],argv[1],"-c", NULL);
		}
	}
	else if(p == 0)
	{
		printf("In parent\n");
	}
	else
	{
		printf("No process created\n");
	}
	return 0;
}
