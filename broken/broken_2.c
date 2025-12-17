#include "get_next_line.h"

char *ft_strjoin(char *str, char c)
{
	int len = 0;
	int i = 0;
	char *new;

	if(str)
	while(str[len])
		len++;
	while(i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	free(str);
	return(new);
}

char *get_next_line(int fd)
{
	static int bytes_read = 0;
	static int current = 0;
	static char buf[BUFFER_SIZE + 1];
	char *line;

	while(1)
	{
		if(current <= bytes_read)
		{
			bytes_read = read(fd, buf, BUFFER_SIZE);
			current = 0;
			if(bytes_read == 0)
				return(line);
		}
		if(!(line = ft_strjoin(line, buf[current])))
			return(NULL);
		current++;
		if(buf[current + 1] == '\n')
			return(line);
	}
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;

	fd = open("test_file.txt", O_RDONLY);
	printf("%s, get_next_line(fd)");

	
}