#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <errno.h>
int main(int argc, char * argv[])
{
	key_t k;
	void *p;
	int shm_id;
	int * a;
	int isNew=1;
	int s_old;
	k = ftok("shm1.c", 0);
	shm_id = shmget(k, 3*sizeof(int), IPC_CREAT|IPC_EXCL|0666);
	if(shm_id < 0)
	{
	        if(errno == EEXIST)
	        {
	                isNew = 0;
			shm_id = shmget(k, 3*sizeof(int), 0);
		}
	}															
	p = shmat(shm_id, NULL, 0);
	if(p != (void *)(-1))
	{
		a = (int *) p;
		if(isNew == 1)
		{
			a[0] = a[1]=a[2]=0;
		}
		s_old = a[2];
		sleep(20);
		a[2] = s_old + 1;
		a[0] += 1;
		//a[2] = a[0] + a[1];
		printf("%d\n",a[2]);
		shmdt(p);
	}
	else if(p == (void *)(-1))
	{
		printf("Can't alloc memory\n");
	}
	return 0;
}



