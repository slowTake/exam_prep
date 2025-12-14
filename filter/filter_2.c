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

int process_input(char *filter)
{
	int bytes_read;
	char *buf[BUFFER_SIZE];
	char *input = NULL;
	int total_len = 0;
	char *temp;
	char *current;
	char *match;

	while((bytes_read = read(0, buf, BUFFER_SIZE)) > 0)
	{
		temp = realloc(input, total_len + bytes_read + 1);
		if(!temp)
		{
			perror("realloc");
			free(input);
			return(1);
		}
		input = temp;
		memmove(input + total_len, buf, bytes_read);
		total_len += bytes_read;
		input[total_len] = '\0';
		bytes_read = 0;
	}

	while(*input)
	{
		match = memmem(input, strlen(input), filter, strlen(filter));
		if(match == input)
		{
			print_stars(filter);
			input += strlen(filter);
		}
		else
		{
			write(1, input, 1);
			input++;
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