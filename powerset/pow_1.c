#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_sol(int **res)
{
	int i = 0;

	while(res[i])
	{
		if(res[i + 1])
			printf("%d ", *res[i]);
		else
			printf("%d", *res[i]);
		i++;
	}
	printf("\n");
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

int find_empty(int **res)
{
	int i = 0;
	
	while(res[i])
		i++;
	return i;
}

void solve(int target, int *subset, int **result, int set_size, int index)
{
	if(sol_found(target, result))
		print_sol(result);
	
	int empty = find_empty(result);

	while(set_size > index)
	{
		result[empty] = &subset[index];
		solve(target, subset, result, set_size, index + 1);
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

	while(set_size > i)
	{
		subset[i] = atoi(argv[i + 2]);
		i++;
	}

	solve(target, subset, res, set_size, 0);

	return 0;
}