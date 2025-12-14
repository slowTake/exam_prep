#include "get_next_line.h"

static char *ft_strjoin_char(char *str, char c)
{
	char *new;
	int i = 0;
	int len = 0;

	if(str)
		while(str[len])
			len++;
	new = malloc(len + 2);
	if(!new)
	{
		free(str);
		return(NULL);
	}
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
	static char buf[BUFFER_SIZE + 1];
	static int buffer_pos = 0;
	static int buffer_read = 0;
	char *line = NULL;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	while(1)
	{
		if(buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buf, BUFFER_SIZE);
			buffer_pos = 0;
			if(buffer_read <= 0)
				return(line);
		}
		if(!(line = ft_strjoin_char(line, buf[buffer_pos])))
			return(NULL);
		if(buf[buffer_pos + 1] == '\n')
			return(line);
	}
}