#define _GNU_SOURCE

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 20000

void print_stars(char *filter)
{
	int len = strlen(filter);

	while(len > 0)
	{
		write(1, "*", 1);
		len--;
	}
}

void process_input(char *filter)
{
	char *buf = NULL;
	int bytes_read = 0;
	char *match;
	char *temp;

	while((bytes_read = read(0, buf, BUFFER_SIZE)) > 0)
	{
		temp = realloc(buf, bytes_read);
		buf = temp;
	}
	while(*buf)
	{
		match = memmem(buf, strlen(buf), filter, strlen(filter));
		if(match == buf)
		{
			print_stars(filter);
			buf+= strlen(filter);
		}
		else
		{
			write(1, buf, 1);
		}
		buf++;
	}
}


int main(int argc, char **argv)
{
	if(argc != 2 || !argv[1][0])
		return(1);
	else
		process_input(argv[1]);
	return(0);
}