#include "get_next_line"

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char *line = NULL;
	int buffer_pos = 0;
	int buffer_read = 0;
	int buffer_

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	while(1)
	{
		if(buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buf, BUFFER_SIZE);
			buffer_pos = 0;
			if(buffer_read <= 0)
				return(line);
		}
	}
	

	return(line);
}