#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct Tms
{
        long mtype;
	        int a;
		};

		int main(int argc, char * argv)
		{
		        //struct Tms M;
			        //M.mtype = 1;
				       // M.a = 1024;
					        key_t key = ftok("msq.c", 'a');
						        int n = sizeof(struct Tms) - sizeof(long);
							        int mqid = msgget(key, IPC_CREAT | 0666);
								       // msgsnd(mqid, &M,n, 0);
									    struct Tms M1;
										        msgrcv(mqid,&M1, n, 1, 0);
											        //printf("%d", M1.mtype);
												        printf("%d", M1.a);
												                return 0;
												                }
