#include <unistd.h>
#include <stdio.h>

int is_balanced(char *str)
{
	int i = 0;
	int count = 0;

	while(str[i])
	{
		if(str[i] == '(')
			count++;
		else if(str[i] == ')')
			count--;
		if(count < 0)
			return(0);
		i++;
	}
	return(count == 0);
}

void solve(char *str, int index, int left, int right)
{
	if(str[index] == '\0')
	{
		if(left == 0 && right == 0 && is_balanced(str))
			puts(str);
		return;
	}

	char backup = str[index];

	if(backup == '(' && left > 0)
	{
		str[index] = ' ';
		solve(str, index + 1, left - 1, right);
		str[index] = backup;
	}
	else if(backup == ')' && right > 0)
	{
		str[index] = ' ';
		solve(str, index + 1, left, right - 1);
		str[index] = backup;
	}
	solve(str, index + 1, left, right);
}

int main(int argc, char **argv)
{
	if(argc == 2 && argv[1][0])
	{
		char *str = argv[1];
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
		solve(str, 0, left, right);
	}	
	return(0);
}
