#include <unistd.h>

void ft_putstr(char *str)
{
	int i = 0;

	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void ft_swap(char *a, char *b)
{
	char tmp = *a;

	*a = *b;
	*b = tmp;
}

void process_input(char *input, int index, int len)
{
	if(index == len)
	{
		ft_putstr(input);
		return;
	}

	for(int i = index; len > i; i++)
	{
		ft_swap(&input[index], &input[i]);

		process_input(input, index + 1, len);

		ft_swap(&input[index], &input[i]);

	}
}

int main(int argc, char **argv)
{
	if(argc != 2 || !argv[1][0])
		return(0);
	else
	{
		int len = 0;

		while(argv[1][len])
			len++;
		
		process_input(argv[1], 0, len);
	}
	return(0);
}