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

char *read_input(void)
{
	int bytes_read;
	char *buf[BUFFER_SIZE];
	char *temp = NULL;
	char *input;

	while((bytes_read = read(0, buf, BUFFER_SIZE) > 0))
	{
		temp = realloc(input, total_len + bytes_read 1);
		if(!temp)
		{
			free(temp);
			perror("realloc");
			return(NULL);
		}
		input = temp;
		memmove(input + total_len, buf, bytes_read);
		total_len += bytes_read;
		input[total_len] = '\0';
		bytes_read = 0;
	}
	if(bytes_read < 0)
	{
		free(input);
		perror(read);
		return(NULL);
	}
	return(input);
}

int process_input(char *filter)
{
	char *current = read_input();
	char *match;

	while(*current)
	{
		match = memmem(current, strlen(current), filter, strlen(filter))
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
}


int main(int argc, char **argv)
{
	if(argc != 2 || !argv[1][0])
		return(1);
	else
		process_input(argv[1]);
	return(0);
}