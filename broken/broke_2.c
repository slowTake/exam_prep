#include "get_next_line.h"

static char *ft_strjoin_char(char *str, char c)
{
	int len = 0;
	int i = 0;
	char *new;

	if(str)
		while(str[len])
			len++;
	
	new = malloc(len + 2);
	if(!new)
	{
		free(str);
		return(NULL);
	}

	while(len > i)
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
    static int buf_pos = 0;
    static int bytes_read = 0;
    static char buf[BUFFER_SIZE + 2];
    char *line = NULL;

    while(1)
    {
        if(fd < 0 || BUFFER_SIZE <= 0)
            return(NULL);
        if(buf_pos >= bytes_read)
        {
			bytes_read = read(fd, buf, BUFFER_SIZE);
			buf_pos = 0;
			if(bytes_read <= 0)
				return(line);
        }
		char c = buf[buf_pos++];
		line = ft_strjoin_char(line, c);
		if(c == '\n')
			break;
    }
	return(line);
}

#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;

    fd = open("test_file.txt", O_RDONLY);

    printf("line : %s\n", get_next_line(fd));
    printf("line : %s\n", get_next_line(fd));
    printf("line : %s\n", get_next_line(fd));
    printf("line : %s\n", get_next_line(fd));
    printf("line : %s\n", get_next_line(fd));
    printf("line : %s\n", get_next_line(fd));
    printf("line : %s\n", get_next_line(fd));
    printf("line : %s\n", get_next_line(fd));
    printf("line : %s\n", get_next_line(fd));

}