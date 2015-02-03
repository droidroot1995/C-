#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/mman.h>

struct Tcoord
{
	double x,y;
};

int main(int argc, char * argv[])
{
	int fd;
	int i;
	fd = open(argv[1], O_CREAT|O_RDWR,0666);
	int n = 1000*sizeof(struct Tcoord);
	void * mem = mmap(NULL,n, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	/*if(MAP_FAILED == (void *)(-1))
	{
		perror("");
		exit(-1);
	}*/
	struct Tcoord * coord = (struct Tcoord *) mem;
	for(i = 0; i< 1000; i++)
	{
		printf("x = %lf, y = %lf\n", coord[i].x, coord[i].y);
	}
	return 0;
}
