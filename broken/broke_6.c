#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char* ft_strjoin_c(char *str, char c)
{
    char *new;
    int len = 0;
    int i = 0;

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
    static int bytes_read = 0;
    static int buf_pos = 0;
    static char buf[BUFFER_SIZE + 2];
    char *line = NULL;

    while(1)
    {
        if(buf_pos >= bytes_read)
        {
            bytes_read = read(fd, buf, BUFFER_SIZE);
            buf_pos = 0;
            if(bytes_read <= 0)
                return(line);
        }
        char c = buf[buf_pos++];
        line = ft_strjoin_c(line, c);
        if(c == '\n')
            break;
    }
    return(line);
}

int main(void)
{
    int fd;
    fd = open("test_file.txt", O_RDONLY);
    char *line = NULL;

    while((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
}