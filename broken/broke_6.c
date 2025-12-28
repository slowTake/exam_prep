#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char *ft_strjoin_char(char *str, char c)
{
    int len = 0;
    int i = 0;
    char *new = NULL;

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
    static char buf[BUFFER_SIZE];
    static int buf_pos = 0;
    static int bytes_read = 0;
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
        line = ft_strjoin_char(line, c);
        if(c = '\n')
            break;
    }

}

int main(void)
{
    int fd = open("test_file.txt", O_RDONLY);
    char *line = NULL;

    while(line = get_next_line(fd))
    {
        printf("%s", line);
        free(line);
    }
}