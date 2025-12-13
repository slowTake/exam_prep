#define _GNU_SOURCE

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100000

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
	char *match;
	int bytes_read = 0;

	buf = malloc(BUFFER_SIZE + 1);
	bytes_read = read(0, buf, BUFFER_SIZE);
	buf[bytes_read] = '\0';
	
	while(buf)
	{
		match = memmem(buf, strlen(buf), filter, strlen(filter));
		if(buf == match)
		{
			print_stars(filter);
			buf+= strlen(filter);
		}
		else
		{
			write(1, buf, 1);
			buf++;
		}
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