#include <stdio.h>
#include <unistd.h>

void ft_sort(char *str, int len)
{
	int i = 0;
	char tmp;

	while(i < len)
	{
		int j = i + 1;
		
		while(j < len)
		{
			if(str[i] > str[j])
			{
				tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void process_input(char *input, char *res, int *used, int pos, int len)
{
	int i = 0;

	if(pos == len)
	{
		res[pos] = '\0';
		puts(res);
		return;
	}

	while(i < len)
	{
		if(!used[i])
		{
			used[i] = 1;
			res[pos] = input[i];
			process_input(input, res, used, pos + 1, len);
			used[i] = 0;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if(argc == 2 && argv[1][0])
	{
		char res[100];
		int used[100] = {0};
		int len = 0;

		while(argv[1][len])
			len++;

		ft_sort(argv[1], len);
		process_input(argv[1], res, used, 0, len);
	}
	return(0);
}