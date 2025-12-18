#define _GNU_SOURCE

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
	char *input = NULL;
	char *match;
	char *current;
	char buf[BUFFER_SIZE];
	char *temp;
	int total_len = 0;

	while((bytes_read = read(0, buf, BUFFER_SIZE))>0)
	{
		input = realloc(input, bytes_read + total_len);
		// if(!temp)
		// {
		// 	free(input);
		// 	perror("realloc failed");
		// 	return(1);
		// }
		// printf("here1?");

		memmove(input + total_len, buf, bytes_read + 1);
		total_len += bytes_read;
		// input = temp;
	}
	current = input;

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
	return(0);
}