#include "get_next_line.h"

#include <string.h>

char *extract_line(char *buf)
{
	char *line;

	line = buf;

	while(*line)
	{
		if(*line == '\n')
		{
			*line = '\0';
			return(line);
		}
		line++;
	}
	return(NULL);
}

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char *current; 
	char *line = NULL;
	int bytes_read = 0;
	char *nl_pos = NULL;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	line = malloc(100000000);
	while(1)
	{
		read(fd, line, BUFFER_SIZE);
		if((nl_pos = strchr(line, '\n')))
		{
			return(extract_line(line));
		}
	}
	return(line);
}

#include <stdio.h> // printf testing
#include <fcntl.h> // open testing 

int	main(void)
{
	int     fd;

	fd = open("test_file.txt", O_RDONLY);
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	printf("get_next_line return: %s\n", get_next_line(fd));
	// printf("get_next_line return: %s\n", get_next_line(fd));
	// printf("get_next_line return: %s\n", get_next_line(fd));
	return(0);
}
