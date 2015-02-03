#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

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

struct TreqBuf
{
	long mtype;
	pid_t pid;
	char req_type;
	char s[33];
};

struct Tans1
{
	long mtype;
	float res;
};

struct Tans2
{
	long mtype;
	char s[33];
};
int main(int argc, char * argv[])
{
	printf("Server started\n");
	key_t key = ftok("server.c", 1234);
	int i;
	char buff[4];
	int id = msgget(key, IPC_CREAT|0666);
	int n1 = sizeof(struct Treq1) - sizeof(long);
	int n2 = sizeof(struct Treq2) - sizeof(long);
	int mn = sizeof (struct TreqBuf) - sizeof(long);
	int m1 = sizeof(struct Tans1) - sizeof(long);
	int m2 = sizeof(struct Tans2) - sizeof(long);
	int rcvid;
	struct Treq1 req1;
	struct Tans1 ans1;
	struct Treq2 req2;
	struct Tans2 ans2;
	struct TreqBuf buf;
	for(;;)
	{
		rcvid = msgrcv(id, &buf, mn, 1, 0);
		printf("Request received\n");
		if(buf.req_type == 's')
		{
			req2 = buf;
			ans2.mtype = req2.pid;
			ans2.s = "pong";
			msgsnd(id, &ans2, m2, 0);
		}
		else
		{
			req1.mtype = buf.mtype;
			req1.pid = buf.pid;
			req1.req_type = buf.req_type;
			req1.op = buf.s[9];
			for(i = 0; i< 4; i++)
			{
				buff[i] = buf.s[i];
			}
			req1.a = atof(buff);
			for(i = 4; i<8; i++)
			{
				buff[i-4] = buf.s[i];
			}
			req1.b = atof(buff);
			ans1.mtype = req1.pid;
			switch(req1.op)
			{
				case '+':
					ans1.res = req1.a + req1.b;
					break;
				case '-':
					ans1.res = req1.a - req1.b;
					break;
				case '*':
					ans1.res = req1.a * req1.b;
					break;
				case '/':
					if(req1.b == 0)
					{
						ans1.res = atof("NaN");
					}
					else
					{	
						ans1.res = req1.a / req1.b;
					}
					break;
				default:
					break;
			}	
			msgsnd(id, &ans1, m1, 0);
			printf("Answer sent\n");
		}
	}
	return 0;
}


