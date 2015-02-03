#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
	char app[5]= {'0','1','2','3','4'};
	int fd;
	mknod("pipe1", S_IFIFO|0644,0);
	fd = open("pipe1", O_WRONLY);
	write(fd, app, 5);
	close(fd);
	unlink("pipe1");
	return 0;
}

