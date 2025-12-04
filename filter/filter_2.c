#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 20
#endif

void ft_filter(char *haystack, char *filter);

int main(int argc, char *argv[])
{
	char *temp[BUFFER_SIZE];
	char *buffer;
	char *haystack = NULL;
	int total_read;
	int read_bytes = 0;

	if(argc != 2)
		return (1);
	while((read_bytes = read(0, temp, BUFFER_SIZE)) > 0)
	{
		buffer = realloc(haystack, (total_read + read_bytes + 1));
		if(!buffer)
		{
			perror("realloc");
			free(buffer);
			return(1);
		}
		haystack = buffer;
		memmove((haystack + total_read), temp, read_bytes);
		total_read = total_read + read_bytes;
		haystack[total_read] = '\0';
	}

	if(read_bytes < 0)
	{
		free(haystack);
		perror("bytes");
		return(1);
	}
	if(!haystack)
	{
		free(haystack);
		return(1);
	}
	ft_filter(haystack, argv[1]);
	free(haystack);
	return(0);
}

void ft_filter(char *haystack, char *filter)
{
	char *match;
	char *current;
	current = haystack;

	if(!filter)
		return(1);

	while(*current)
	{
		match = memmem(haystack, strlen(haystack), filter, strlen(filter));
		if(match == current)
		{
			
		}

	}

}
