#include <unistd.h>
#include <stdio.h>

void sort_str(char *str, int len)
{
	int i = 0;
	int j;

	while(len > i)
	{
		j = i + 1;

		while(len > j)
		{
			if(str[i] > str[j])
			{
				char temp = str[i];
				str[i] = str[j];
				str[j] = temp;	
			}
			j++;
		}
		i++;
	}
}

void solve(char *str, char *res, int *used, int pos, int len)
{
	int i = 0;

	if(pos == len)
	{
		res[pos] = '\0';
		puts(res);
		return;
	}

	while(len > i)
	{
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
	if(argc == 2 && argv[1][0])
	{
		int unused[100] = {0};
		char res[100];

		int len = 0;
		while(argv[1][len])
			len++;

		sort_str(argv[1], len);
		solve(argv[1], res, unused, 0, len);
	}
	return(0);
}