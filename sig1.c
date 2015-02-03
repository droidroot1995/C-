#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

void * hndlchld(int sig)
{
	int status;
	waitpid(-1, &status, 0);
	if(WIFEXITED(status))
	{
		int retcode = WEXITSTATUS(status);
		printf("Process exited %d\n", retcode);
	}
	if(WIFSIGNALED(status))
	{
		int sig1 = WTERMSIG(status);
		printf("Process Killed %d\n",sig1);
	}
	exit(-1);
}

int main(int argc, char * argv[])
{
	int p = fork();
	if(p > 0)
	{
		while(1)
		{
			signal(SIGCHLD,hndlchld);
		}
	}
	else if(p == -1)
	{
		printf("Error while creating process!!!\n");
		exit(-1);
	}
	else
	{
		return -1;
	}
	return 0;
}
