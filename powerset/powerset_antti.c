#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int find_empty(int **result)
{
	int i = 0;

	while(result[i])
		i++;
	return i;
}

int sol_found(int target, int **result)
{
	int i = 0;
	int sum = 0;

	while(result[i])
	{
		sum += *result[i];
		i++;
	}

	if(target == sum)
		return 1;
	return 0;
}

void print_sol(int **result)
{
	int i = 0;

	while(result[i])
	{
		if(result[i + 1])
			printf("%d ", *result[i]);
		else
			printf("%d", *result[i]);
		i++;
	}
	printf("\n");
}

void solve(int target, int *subset, int **result, int len, int index)
{
	if(sol_found(target, result))
		(print_sol(result));
	
	int empty = find_empty(result);

	while(len > index)
	{
		result[empty] = &subset[index];
		solve(target, subset, result, len, index + 1);
		result[empty] = 0;
		index++;
	}
}

int main(int argc, char **argv)
{
	if(argc < 2)
		return 0;
	
	int target = atoi(argv[1]);
	int set_size = argc - 2;

	int *subset = calloc(1, sizeof(int) * set_size);
	int **res = calloc(1, sizeof(int *) * (set_size + 1));
	
	int i = 0;
	while(argv[i + 2])
	{
		subset[i] = atoi(argv[i + 2]);
		i++;
	}
	
	solve(target, subset, res, set_size, 0);

	return 0;
}
