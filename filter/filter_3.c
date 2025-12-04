#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 20
#endif

void process_input(char *filter);
char read_input(void);
void print_stars(int count);

void print_stars(int count)
{
	while(count > 0)
	{
		write(STDOUT_FILENO, "*", 1);
		count--;
	}
}

void process_input(char *filter)
{

}

char read_input(void)
{
	char buf[BUFFER_SIZE];
	int bytes_read = 0;
	char *input = NULL;

	char *temp;

	while(bytes_read = (read(STDOUT_FILENO, buf, bytes_read)) > 0)
	{
		temp = input;
		realloc(input, strlen(input) + bytes_read + 1);
		if(!temp)
		{
			perror("realloc");
			free(input);
			return(NULL);
		}
	


	}
	if(bytes_read < 0)
	{
		free(input);
		perror("read fail");
		return(NULL);
	}
	return(input);
}

void main(int argc, char **argv)
{
	if(argc != 2 || !argv[1][0])
		return(1);
	else
		process_input(argv[1]);
}
