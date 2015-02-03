#include <sys/types.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
	int key, id;
	key = ftok("sem.c", 120);
	id = semget(key, 1, IPC_CREAT|0666);
	//semop(id, Ops, 1);
	struct sembuf Ops[1];
	Ops[0].sem_num = 0;
	Ops[0].sem_op=-1;
	Ops[0].sem_flg = 0;
	semop(id, Ops, 1);
	printf("in program\n");
	return 0;
}

