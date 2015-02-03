#include <unistd.h>
#include <stdio.h>
//#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

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
	printf("Server started\n");
	key_t key = ftok("server.c", 1234);
	int id = msgget(key, IPC_CREAT|0666);
	int n = sizeof(struct Treq) - sizeof(long);
	int m = sizeof(struct Tans) - sizeof(long);
	int rcvid;
	struct Treq req;
	struct Tans ans;
	for(;;)
	{
		rcvid = msgrcv(id, &req, n, 1, 0);
		if(rcvid == -1)
		{
			printf("No requests\n");
		}
		else
		{
			printf("Request received\n");
			ans.mtype = req.pid;
			switch(req.op)
			{
				case '+':
					ans.res = req.a + req.b;
					break;
				case '-':
					ans.res = req.a - req.b;
					break;
				case '*':
					ans.res = req.a * req.b;
					break;
				case '/':
					if(req.b == 0)
					{
						ans.res = atof("NaN");
					}
					else
					{	
						ans.res = req.a / req.b;
					}
					break;
				default:
					break;
			}	
			msgsnd(id, &ans, m, 0);
			printf("Answer sent\n");
		}
	}
	return 0;
}


