#include <unistd.h>
#include <stdio.h>

int ft_len(char *str)
{
	int i = 0;

	while(str[i])
		i++;
		
}

void solve_rip(char *str)
{
	int len = ft_len(str);


}

int main(int argc, char **argv)
{
	if(argc != 2)
		return(1);
	else
	{
		if(balance(argv[1]) == 0)
			solve_rip(argv[1]);
		else
			return(0);
	}
}

int balance(char *str)
{
	int left = 0;
	int right = 0;

	while(*str++)
	{
		if(*str == '(')
			left++;
		if(*str == ')')
			right++;
	}
	if(left == right)
		return(0);
	else 
		return(1);

}