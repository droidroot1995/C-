#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Treq
{
	long mtype;
	pid_t pid;
	float a,b;
	char op;
};

struct Tans
{
	long mtype;
	float res;
};

int main(int argc, char * argv[])
{
	srand(time(NULL));
	struct Treq req;
	struct Tans ans;
	req.mtype = 1;
	req.pid = getpid();
	req.a = rand()%101;
	req.b = rand()%101;
	key_t key = ftok("server.c", 1234);
	int id = msgget(key, IPC_CREAT|0666);
	int ops = rand()%4+1;
	switch(ops)
	{
		case 1:
			req.op = '+';
			break;
		case 2:
			req.op = '-';
			break;
		case 3:
			req.op = '*';
			break;
		case 4:
			req.op = '/';
			break;
		default:
			break;
	}
	int n = sizeof(struct Treq)- sizeof(long);
	int m = sizeof(struct Tans) - sizeof(long);
	msgsnd(id, &req, n, 0);
	printf("Request sent\n");
	int rcvid = msgrcv(id, &ans, m, req.pid, 0);
	printf("Result received\n");
	if(ans.res == atof("NaN"))
	{
		printf("Error!!!\nResult is NaN");
	}
	else
	{
		printf("Result is: %f\n", ans.res);
	}
	return 0;
}
