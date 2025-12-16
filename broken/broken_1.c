#include "get_next_line.h"

static char *ft_strjoin(char *s, char c)
{
	char *new;
	int i = 0;
	int len = 0;

	if(s)
		while(s[len])
			len++;
	new = malloc(len + 2);

	while(i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	free(s);
	return(new);
}

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	static int bytes_read = 0;
	static int current = 0;
	char *line = NULL;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	while(1)
	{
		if(current >= bytes_read)
		{
			bytes_read = read(fd, buf, BUFFER_SIZE);
			current = 0;
			if(bytes_read <= 0)
				return(line);
		}
		if(!(line = ft_strjoin(line, buf[current])))
			return(NULL);
		current++;
		if(buf[current + 1] == '\n')
			return(line);
	}
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
