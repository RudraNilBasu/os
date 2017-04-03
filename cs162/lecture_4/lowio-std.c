#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
	char buf[BUFSIZE];
	ssize_t writelen = write(STDOUT_FILENO, "I am a process.\n", 16);
	ssize_t readlen = read(STDIN_FILENO, buf, BUFSIZE);
	ssize_t strlen = snprintf(buf, BUFSIZE, "Got %zd characters\n",readlen);
	writelen = strlen < BUFSIZE ? strlen : BUFSIZE;
	write(STDOUT_FILENO, buf, writelen);
	exit(0);
}
