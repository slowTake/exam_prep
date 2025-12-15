#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
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

int process_input(char *filter)
{
	char *input = NULL;
	char *match;

	input = calloc(2000000, 1);
	while(read(0, input, BUFFER_SIZE) > 0)
	{

	}
	char *current = input;
	while(*current)
	{
		match = memmem(current, strlen(current), filter, strlen(filter));
		if(match == current)
		{
			print_stars(filter);
			current+=strlen(filter);
		}
		else
		{
			write(1, current, 1);
			current++;
		}
	}
	free(input);
	return(0);
}

int main(int argc, char **argv)
{
	if(argc != 2 || !argv[1][0])
		return(1);
	else
	{
		// printf("test");
		process_input(argv[1]);
	}
	return(0);
}