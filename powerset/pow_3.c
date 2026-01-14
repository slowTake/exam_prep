#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int find_empty(int **res)
{
	int i = 0;

	while(res[i])
		i++;
	return i;
}

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

int find_sol(int target, int **res)
{
	int i = 0;
	int sum = 0;

	while(res[i])
	{
		sum += *res[i];
		i++;
	}
	if(target == sum)
		return 1;
	return 0;
}

void solve(int target, int **res, int *subset, int pos, int set_size)
{
	if(find_sol(target, res))
		print_sol(res);
	
	int empty = find_empty(res);

	while(set_size > pos)
	{
		res[empty] = &subset[pos];
		solve(target, res, subset, pos + 1, set_size);
		res[empty] = 0;
		pos++;
	}
}

int main(int argc, char **argv)
{
	if(argc < 2)
		return 0;
	
	int target = atoi(argv[1]);
	int set_size = argc - 2;
	int **res = calloc(1, sizeof(int *) * (set_size + 1));
	int *subset = calloc(1, sizeof(int) * set_size);

	int i = 0;
	while(argv[i + 2])
	{
		subset[i] = atoi(argv[i + 2]);
		i++;
	}

	solve(target, res, subset, 0, set_size);
}