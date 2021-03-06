/*
 * Create a custom signal callback handler
 */
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

#include<unistd.h>
#include<signal.h>

void signal_callback_handler(int signum)
{
	printf("Caught signal %d\n",signum);
	exit(1);
}

int main()
{
	signal(SIGINT, signal_callback_handler);

	while(1) {
	}
}
