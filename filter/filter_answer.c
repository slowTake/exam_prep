#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

#include <string.h> // strlen
#include <unistd.h> // write, read
#include <stdlib.h> // malloc, free, memmove, realloc
#include <stdio.h> // fprintf used for streams

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

char	*read_input(void)
{
	char	*input = NULL;
	char	buf[BUFFER_SIZE];
	int		read_bytes = 0;
	int		total_len = 0;
	char	*temp;

	while ((read_bytes = read(STDIN_FILENO, buf, BUFFER_SIZE)) > 0)
	{
		temp = realloc(input, total_len + read_bytes + 1);
		if (!temp)
		{
			free(input);
			fprintf(stderr, "error\n");
			return (NULL);
		}
		input = temp;
		memmove(input + total_len, buf, read_bytes);
		total_len += read_bytes;
		input[total_len] = '\0';
		read_bytes = 0;
	}
	if (read_bytes < 0)
	{
		free(input);
		fprintf(stderr, "error\n");
		return (NULL);
	}
	return (input);
}

void	print_stars(int len)
{
	int	i = 0;
	while (i < len)
	{
		write(1, "*", 1);
		i++;
	}
}

int	process_input(char *filter)
{
	int	filter_len = strlen(filter);
	char	*input = read_input();
	char	*current;
	char	*match;

	if(!input)
		return (1);
	current = input;
	while (*current)
	{
		match = memmem(current, strlen(current), filter, filter_len);
		if (match == current)
		{
			print_stars(filter_len);
			current += filter_len;
		}
		else
		{
			write(1, current, 1);
			current++;
		}
	}
	free(input);
	
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0])
		return (1);
	return (process_input(argv[1]));
}
