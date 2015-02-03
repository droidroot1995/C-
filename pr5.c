#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
	char app[5];
	int i;
	int fd;
	fd = open("pipe1", O_RDONLY);
	read(fd, app, 5);
	close(fd);
	for(i = 0; i< 5; i++)
		printf("%c ", app[i]);
	printf("\n");
	unlink("pipe1");
	return 0;
}
