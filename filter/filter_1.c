#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 20000
#endif

void print_stars(char *filter)
{
	int len = strlen(filter);

	while(len > 0)
	{
		write(1, "*", 1);
		len--;
	}
}

void process_input(char *filter)
{
	char *buf = NULL;
	char *match;

	buf = malloc(BUFFER_SIZE);
	read(0, buf, BUFFER_SIZE);


	while(*buf)
	{
		match = memmem(buf, strlen(buf), filter, strlen(filter));
		if(match == buf)
		{
			print_stars(filter);
			buf += strlen(filter);
		}
		else
		{
			write(1, buf, 1);
			buf++;
		}
	}
}

int main(int argc, char **argv)
{
	if(argc != 2 || !argv[1][0])
		return(1);
	else
		process_input(argv[1]);
	return(0);
}
