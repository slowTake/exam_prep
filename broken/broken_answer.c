#include "get_next_line.h"

static char *ft_strjoin_char(char *str, char c)
{
    char *new;
    int i = 0;
    int len = 0;

    if (str)
        while (str[len])
            len++;
    if (!(new = malloc(len + 2)))
	{
		free(str);
        return (NULL);
	}
	while (i < len)
    {
        new[i] = str[i];
        i++;
    }
    new[i] = c;
    new[i + 1] = '\0'; 
    free(str);
    return (new);
}

char *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    static int  buf_pos = 0;
    static int  bytes_read = 0;
    char        *line = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
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
