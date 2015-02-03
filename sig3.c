#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

static int count = 0;

void * hndlchld(int sig)
{
        int status;
	count++;
	while(waitpid(-1, &status, WNOHANG) > 0)
	{
        if(WIFEXITED(status))
        {
                int retcode = WEXITSTATUS(status);
                printf("Process exited %d\n", retcode);
        }
        if(WIFSIGNALED(status))
        {
                int sig1 = WTERMSIG(status);
                printf("Process killed %d\n",sig1);
        }
	}
	//exit(-1);
}


int main(int argc, char * argv[])
{
	int i = 0;
	//int p[5];
	for(;i<6; i++)
	{
        int p = fork();
        if(p > 0)
        {
	//	int mypid = getpid();
	//	return mypid;
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
		int my_pid = getpid();
		return my_pid;
        }
	}
      return 0;
}
 
