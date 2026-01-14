#include <unistd.h>
#include <stdio.h>

int is_balanced(char *str)
{
	int left = 0;
	int right = 0;
	int i = 0;

	while(str[i])
	{
		if(str[i] == '(')
			left++;
		else if (str[i] == ')')
		{
			if(left > 0)
				left--;
			else
				right++;
		}
		i++;
	}
	return(left == 0 && right == 0);
}

void solve(char *str, int pos, int left, int right)
{
	if(str[pos] == '\0')
	{
		if(left == 0 && right == 0 && is_balanced(str))
			puts(str);
		return ;
	}

	int i = 0;
	char backup = str[pos];

	if(backup == '(' && left > 0)
	{
		str[pos] = ' ';
		solve(str, pos + 1, left - 1, right);
		str[pos] = backup;
	}
	else if(backup == ')' && right > 0)
	{
		str[pos] = ' ';
		solve(str, pos + 1, left - 1, right);
		str[pos] = backup;
	}
	solve(str, pos + 1, left, right);
}

int main(int argc, char **argv)
{
	if(argc == 2 && argv[1][0])
	{
		int left = 0;
		int right = 0;
		int i = 0;
		char *str = argv[1];

		while(str[i])
		{
			if(str[i] == '(')
				left++;
			else if (str[i] == ')')
			{
				if(left > 0)
					left--;
				else
					right++;
			}
			i++;
		}
		solve(argv[1], 0, left, right);
	}
}