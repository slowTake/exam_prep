#define _GNU_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
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

int *process_input(char *filter)
{
	char *input = NULL;
	char buf[BUFFER_SIZE];
	int bytes_read = 0;
	int total_len = 0;
	char *current;
	char *match;

	while((bytes_read = read(0, buf, BUFFER_SIZE)) > 0)
	{
		input = realloc(input, bytes_read + total_len + 1);
		memmove(input + total_len, buf, bytes_read);
		total_len += bytes_read;
		bytes_read = 0;
	}
	
	current = input;

	while(*current)
	{
		match = memmem(current, strlen(current), filter, strlen(filter));
		if(match == current)
		{
			print_stars(filter);
			current += strlen(filter);
		}
		else
		{
			write(1, current, 1);
			current++;
		}
	}
	return(0);
}

int main(int argc, char **argv)
{
	if(argc != 2 || !argv[1][0])
		return(1);
	else
		process_input(argv[1]);
	return(0);
}
