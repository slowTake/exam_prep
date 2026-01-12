#include <stdlib.h>
#include <stdio.h>

/**
 * Helper to print the current subset.
 * If subsize is 0, it simply prints a newline (representing the empty set).
 */
void print_subset(int *subset, int subsize)
{
	int i = 0;

	while (i < subsize)
	{
		printf("%d", subset[i]);
		if (i < subsize - 1)
			printf(" ");
		i++;
	}
	printf("\n");
}

/**
 * The recursive backtracking function.
 * @param target: The sum we are looking for.
 * @param set: The original input numbers.
 * @param set_size: Total count of input numbers.
 * @param idx: Our current position in the input set.
 * @param subset: Buffer to store the numbers we "pick".
 * @param subsize: How many numbers are currently in our subset buffer.
 * @param current_sum: The running total of the numbers in our subset.
 */
void solve(int target, int *set, int set_size, int idx, int *subset, int subsize, int current_sum)
{
	// Base Case: We have made a decision for every number in the original set.
	if (idx == set_size)
	{
		if (current_sum == target)
		{
			print_subset(subset, subsize);
		}
		return;
	}

	/* * CHOICE 1: SKIP the current element.
	 * We move to the next index without adding set[idx] to our sum or buffer.
	 * This branch is explored first to naturally handle smaller/empty subsets.
	 */
	solve(target, set, set_size, idx + 1, subset, subsize, current_sum);

	/* * CHOICE 2: PICK the current element.
	 * Add the number to our buffer and update the running sum.
	 */
	subset[subsize] = set[idx];
	solve(target, set, set_size, idx + 1, subset, subsize + 1, current_sum + set[idx]);
}

int main(int argc, char **argv)
{
	// The subject implies n and the set s follow ./powerset.
	// If argc < 2, the target 'n' isn't even provided.
	if (argc < 2)
		return (0);

	int target = atoi(argv[1]);
	int set_size = argc - 2;

	// Handle malloc as required by the subject.
	int *set = malloc(sizeof(int) * set_size);
	int *subset = malloc(sizeof(int) * set_size);

	if (!set || !subset)
	{
		free(set);
		free(subset);
		return (1); // Exit code 1 for malloc error as per subject.
	}

	// Fill the set array with integers from argv.
	int i = 0;
	while (i < set_size)
	{
		set[i] = atoi(argv[i + 2]);
		i++;
	}

	// Start recursion: index 0, empty subset (size 0), current_sum 0.
	solve(target, set, set_size, 0, subset, 0, 0);

	free(set);
	free(subset);
	return (0);
}