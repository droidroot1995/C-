#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>

struct Tcoord
{
	double x,y;
};

int main(int argc, char * argv[])
{
	srand(time(NULL));
	int i;
	int fd;
	fd = open(argv[1], O_CREAT|O_RDWR,0666);
	int n = 1000 * sizeof(struct Tcoord);
	ftruncate(fd, n);
	void * mem = mmap(NULL,n, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);
	/*if(MAP_FAILED == (void*)-1)
	{
		perror("");
		exit(-1);
	}*/
	struct Tcoord * coord = (struct Tcoord *) mem;
	for(i = 0; i < 1000; i++)
	{
		coord[i].x = rand()%1000;
		coord[i].y = rand()%1000;
	}
	munmap(mem, n);
	return 0;
}
