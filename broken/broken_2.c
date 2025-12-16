#include "get_next_line.h"

char *get_next_line(int fd)
{
	static int bytes_read = 0;
	char buf[BUFFER_SIZE + 1];

}