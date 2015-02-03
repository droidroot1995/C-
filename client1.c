#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Treq1
{
	long mtype;
	pid_t pid;
	char req_type;
	float a,b;
	char op;
};

struct Treq2
{
	long mtype;
	pid_t pid;
	char req_type;
	char s [33];
};

struct Tans1
{
	long mtype;
	float res;
};

struct Tans2
{
	long mtype;
	char s [33];
};

int main(int argc, char * argv[])
{
	srand(time(NULL));
	
	int type = rand()%2+1;
	if( type == 1)
	{
		struct Treq1 req;
		struct Tans1 ans;
		req.mtype = 1;
		req.pid = getpid();
		req.req_type = 'n';
		req.a = rand()%101;
		req.b = rand()%101;
		key_t key = ftok("server1.c", 1234);
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
		int n = sizeof(struct Treq1)- sizeof(long);
		int m = sizeof(struct Tans1) - sizeof(long);
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
	}
	else
	{
		struct Treq2 req;
		struct Tans2 ans;
		req.mtype = 1;
		req.pid = getpid();
		req.req_type = "s";
		req.s = "ping";
		key_t key = ftok("server1.c", 1234);
		int id = msgget(key, IPC_CREAT|0666);
		int n = sizeof(struct Treq2)- sizeof(long);
		int m = sizeof(struct Tans2) - sizeof(long);
		msgsnd(id, &req, n, 0);
		printf("Request sent\n");
		int rcvid = msgrcv(id, &ans, m, req.pid, 0);
		printf("Result received\n");
		printf("Result is: %c\n", ans.s);
	}
	return 0;
}
