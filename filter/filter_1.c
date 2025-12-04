#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

char	*read_input(void)
{
	char	*input = NULL;
	int		read_bytes = 0;
	int		total_len = 0;
	char 	buf[BUFFER_SIZE];
	char	*temp;
	
	while((read_bytes = read(STDIN_FILENO, buf, BUFFER_SIZE)) > 0)
	{
		input = realloc(input, total_len + read_bytes + 1);
		if(!input)
		{
			free(input);
			perror("realloc");
			return(NULL);
		}
		input = temp;


		
	}
	
}

int *process_input(char *filter)
{
	
}

void main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("\n error");
	}
	else
	{
		process_input(argv[1]);
	}
}

