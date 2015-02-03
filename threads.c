#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/sem.h>

int semid;
key_t key;

struct sembuf ops[1];
struct sembuf ops1[1];
	

int sum = 0;
void * sum1()
{
	semid = semget(key, 1, IPC_CREAT|0666);
	semop(semid, ops, 1);
	sum++;
	printf("%d\n", sum);
	semop(semid, ops1, 1);

}

void * sum2()
{
	semid = semget(key, 1, IPC_CREAT|0666);
	semop(semid, ops, 1);
	sum++;
	printf("%d\n", sum);
	semop(semid, ops1, 1);
}
int main(int argc, char * argv[])
{
	semid = semget(key, 1 , IPC_CREAT|0666);
	ops[0].sem_num = 0;
	ops[0].sem_num = 1;
	ops[0].sem_num = 0;
	ops1[0].sem_num = 0;
	ops1[0].sem_num = -1;
	ops1[0].sem_num = 0;
	semop(semid, ops, 1);
	key = ftok("threads.c", 123);
	int i = 0;
	pthread_t thid = 3;
	pthread_t thid1 = 2;
	for(; i< 100; i++)
	{
		pthread_create(&thid, NULL, sum1, NULL);
		pthread_create(&thid1, NULL,sum2, NULL);
	}
	return 0;
}

