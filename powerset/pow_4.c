#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int find_empty(int **res)
{

}

int sol_found()
{

}

void print_sol()
{

}

void solve(int target, int *subset, int **res, int pos, int len)
{
	if(sol_found(target, res))
		print_sol(res);
	
	int empty = find_empty(res);

	while(len > pos)
	{
		res[empty] = &subset[pos];
		solve(target, subset, res, pos + 1, len);
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

	solve(target, subset, res, 0, i);
}