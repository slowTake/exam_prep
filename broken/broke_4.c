#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char *ft_strjoin_char(char *str, char c)
{
    char *new;
    int i = 0;
    int len = 0;

    if (str)
        while (str[len])
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
    static char buf[BUFFER_SIZE + 1];
    static int buf_pos = 0;
    static int bytes_read = 0;
    char *line = NULL;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
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
        if(c == '\n')
            break;
    }
    return(line);
}

int main(void)
{
    int fd; 
    fd = open("open.txt", O_RDONLY);
    int i = 1;
    char *line = NULL;

    while((line = get_next_line(fd)))
    {
        printf("line: %d: %s", i++, line);
        free(line);
    }

}
