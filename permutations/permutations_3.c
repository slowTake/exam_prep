#include <stdio.h>
#include <unistd.h>

void ft_sort(char *str, int len)
{
	int i = 0;
	char tmp;
	int j;

	while(len > i)
	{
		j = i + 1;
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
	return;
}

void solve(char *str, char *res, int *used, int pos, int len)
{
	if(pos == len)
	{
		res[pos] = '\0';
		puts(res);
		return;
	}

	int i = 0;

	while(len > i)
	{
		// printf("%d", i);
		if(!used[i])
		{
			used[i] = 1;
			res[pos] = str[i];
			solve(str, res, used, pos + 1, len);
			used[i] = 0;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int used[100] = {0};
	char res[100];

	if(argc == 2 && argv[1][0])
	{
		int len = 0;
		while(argv[1][len])
			len++;
		ft_sort(argv[1], len);
		solve(argv[1], res, used, 0, len);
	}
	return(0);
}