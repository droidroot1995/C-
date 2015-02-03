#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
	int fd[2];
	char app[5]={'0','1','2','3','4'};
	char app1[5];
	int i;
	int err;
	err = pipe(fd);
	int p = fork();
	if( p== 0)
	{
		close(fd[1]);
		read(fd[0], app1, 5);
		for(i = 0; i<5; i++)
		{
			printf("%c ", app1[i]);
		}
		printf("\n");
	}
	else if(p > 0)
	{
		close(fd[0]);
		write(fd[1], app, 5);
	}
	return 0;
}

