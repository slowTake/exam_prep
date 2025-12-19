#define _GNU_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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
	int bytes_read = 0;
	char buf[BUFFER_SIZE];
	char *temp;
	char *input = NULL;
	int total_len = 0;

	while((bytes_read = read(0, buf, BUFFER_SIZE)) > 0)
	{
		temp = realloc(input, total_len + bytes_read + 2);
		input = temp;
		memmove(input + total_len, buf, bytes_read);
		total_len += bytes_read;
	}

	char *match;
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
		process_input(argv[1]);
}