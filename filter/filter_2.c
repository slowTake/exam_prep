#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

void print_stars(char *filter , int flen)
{

	while(flen > 0)
	{
		write(1, "*", 1);
		flen--;
	}
}

int process_input(char *filter)
{
	char buf[BUFFER_SIZE];
	int bytes_read = 0;
	char *input = NULL;
	int total_size = 0;
	char *temp;

	while((bytes_read = read(0, buf, BUFFER_SIZE)) > 0)
	{
		temp = realloc(input, total_size + bytes_read + 2);
		if(!temp)
		{
			perror("realloc");
			free(input);
			return(1);
		}
		memmove(temp + total_size, buf, bytes_read);
		total_size+=bytes_read;
		input = temp;
	}
	char *current = input;
	char *match;
	int flen = strlen(filter);

	while(*current)
	{
		match = memmem(current, strlen(current), filter, flen);
		if(match == current)
		{
			print_stars(filter, flen);
			current+= flen;
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
	{
		return(1);
	}
	else
		process_input(argv[1]);
}