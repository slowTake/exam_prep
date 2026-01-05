#include <stdio.h>
#include <unistd.h>

void ft_sort(char *str, int len)
{
	int i = 0;
	char tmp;

	while(len > i)
	{
		int j = i + 1;
		while(len > j)
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

void ft_solve(char *str, char *res, int *used, int pos, int len)
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
			res[pos] = str[i];
			ft_solve(str, res, used, pos + 1, len);
			used[i] = 0;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if(argc == 2 && argv[1][0])
	{
		int used[100] = {0};
		char res[100];
		int len = 0;

		while(argv[1][len])
			len++;
		
		ft_sort(argv[1], len);
		ft_solve(argv[1], res, used, 0, len);
	}
	return(0);
}