#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_sol(int *res, int res_len)
{
    for (int i = 0; i < res_len; i++)
    {
        printf("%d", res[i]);
        if (i < res_len - 1)
            printf(" ");
    }
    printf("\n");
}

void solve(int target, int *subset, int *res, int subset_len, int subset_idx, int res_len, int current_sum)
{
    if (current_sum == target)
    {
        print_sol(res, res_len);
        return;
    }

    if (current_sum > target || subset_idx >= subset_len)
        return;

    // Standard Backtracking: Try including the current number and excluding it
    while (subset_idx < subset_len)
    {
        // 1. Action: Add current number to result
        res[res_len] = subset[subset_idx];
        
        // 2. Recurse: Move to next index with updated sum and length
        solve(target, subset, res, subset_len, subset_idx + 1, res_len + 1, current_sum + subset[subset_idx]);
        
        // 3. Backtrack: Move to next number in the input set
        subset_idx++;
    }
}

int main(int argc, char **argv)
{
	if(argc < 2)
		return 0;
	
	int target = atoi(argv[1]);
	int set_size = argc - 2;

	int *subset = calloc(1, sizeof(int) * set_size);
	int *res = calloc(1, sizeof(int) * set_size);
	
	int i = 0;
	while(set_size > i)
	{
		subset[i] = atoi(argv[i + 2]);
		i++;
	}
	
	solve(target, subset, res, set_size, 0, 0, 0);

	return 0;
}