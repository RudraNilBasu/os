/*
 * Get current process PID
 * A PID is automatically assigned to each process when it is created.
 * A process is nothing but running instance of a program and each 
 * process has a unique PID on a Unix-like system
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

#define BUFSIZE 1024
int main(int argc, char *argv[])
{
	pid_t pid = getpid(); /* Get current process PID */
	printf("Current PID: %d\n",pid);

	int c = fgetc(stdin);
	exit(0);
}
