#define _GNU_SOURCE

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

void print_stars(char *filter)
{
    int len = strlen(filter);

    while(len > 0)
    {
        // printf("test");
        write(1, "*", 1);
        len--;
    }
}

int process_input(char *filter)
{
    int total_len = 0;
    char *temp;
    char *input = NULL;
    int bytes_read = 0;
    char buf[BUFFER_SIZE];

    while((bytes_read = read(0, buf, BUFFER_SIZE))> 0)
    {
        temp = realloc(input, total_len + bytes_read + 2);
        if(!temp)
        {
            perror("realloc");
            free(input);
            return(1);
        }
        memmove(temp + total_len, buf, bytes_read);
        total_len += bytes_read;
        input = temp;
    }


    char *current = input;
    char *match;

    while(*current)
    {
        match = memmem(current, strlen(current), filter, strlen(filter));
        if(match == current)
        {
            // printf("test");
            print_stars(filter);
            current += strlen(filter);
        }
        else
        {
            write(1, current, 1);
            current++;
        }
    }
    return(0);
}

int main(int argc, char **argv)
{
    if(argc != 2 || !argv[1][0])
        return(0);
    else
        process_input(argv[1]);
}