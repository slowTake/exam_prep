#include <stdlib.h>
#include <stdio.h>

void print_subset(int *subset, int subsize)
{
	int i = 0;

	while (i < subsize)
	{
		printf("%d", subset[i]);
		if(i < subsize -1)
			printf(" ");
		i++;
	}
	printf("\n");
}

void solve(int target, int *set, int set_size, int idx, int *subset, int subsize, int current_sum)
{
	if(idx == set_size)
	{
		if(current_sum == target)
		{
			print_subset(subset, subsize);
		}
		return;
	}
	solve(target, set, set_size, idx + 1, subset, subsize, current_sum);
	subset[subsize] = set[idx];
	solve(target, set, set_size, idx + 1, subset, subsize + 1, current_sum + set[idx]);
}

int main(int argc, char **argv)
{
	if(argc < 2)
		return 0;
	
	int target = atoi(argv[1]);
	int set_size = argc - 2;

	int *set = malloc(sizeof(int) * set_size);
	int *subset = malloc(sizeof(int) * set_size);

	if(!set || !subset)
	{
		free(set);
		free(subset);
		return 1;
	}

	int i = 0;
	while(set_size > i)
	{
		set[i] = atoi(argv[i + 2]);
		i++;
	}
	solve(target, set, set_size, 0, subset, 0, 0);

	free(set);
	free(subset);
	return 0;
}
