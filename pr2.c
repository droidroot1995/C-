#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
	int fd;
	int i;
	char app [5] = {'0','1','2','3','\0'};
	char app1 [5];
	fd = open("text", O_CREAT|O_WRONLY, 0666);
	write(fd, app, 5);
	close(fd);
	fd = open("text", O_CREAT | O_RDONLY, 0666);
	read(fd, app1, 5);
	for(i = 0; i<5; i++)
		printf("%c", app1[i]);
	printf("\n");
	close(fd);
	return 0;
}
