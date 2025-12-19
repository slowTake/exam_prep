#include "get_next_line.h"

static char *ft_strjoin_char(char *str, char c)
{
	char *new;
	int len = 0;
	int i = 0;

	if(str)
		while(str[len])
			len++;
	
	if(!(new = malloc(len + 2)))
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
	static int bytes_read = 0;
	static int buf_position = 0;
	char *line = NULL;

	
}