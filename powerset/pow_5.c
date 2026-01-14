#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int sol_found();
void print_sol();
int find_empty();

void solve(int target, int **res, int *subset, int pos, int len)
{
	if(sol_found(target, res))
		print_sol(res);
	
	int empty = find_empty(res);

	int i = 0;
	while(len > pos)
	{
		res[empty] = &subset[i];
		solve(target, res, subset, pos + 1, len);
		res[empty] = 0;
		pos++;
	}
}

int main(int argc, char **argv)
{
	if(argc < 2)
		return 0;
	

	int target = atoi(argv[1]);
	int subsize = argc - 2;
	int **res = calloc(1, sizeof(int *) * (subsize + 1));
	int *subset = calloc(1, sizeof(int *) * subsize);

	int i = 0;

	while(argv[i + 2])
	{
		subset[i] = atoi(argv[i + 2]);
		i++;
	}

	solve(target, res, subset, 0, subsize);
}