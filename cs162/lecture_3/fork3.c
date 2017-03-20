/* Fork a process
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
	char buf[BUFSIZE];
	size_t readlen, writelen, slen;
	pid_t cpid, mypid;
	pid_t pid = getpid();
	printf("Parent pid: %d\n",pid);
	cpid = fork();
	int i;
	/* Parent and the child run in parallel */
	if(cpid > 0) {
		/* Parent Process*/
		mypid = getpid();
		printf("[%d] Parent pid of [%d]\n",mypid,cpid);
		for(i = 0;i < 100;i++) {
			printf("[%d] parent %d\n", mypid, i);
		}
	} else if(cpid == 0) {
		/* Child Process */
		mypid = getpid();
		printf("[%d] child\n",mypid);
		for(i = 0; i > -100; i--) {
			printf("[%d] child %d\n", mypid, i);
		}
	} else if(cpid < 0) {
		/* Error */
		perror("Fork Failed\n");
		exit(1);
	}
	exit(0);
}
