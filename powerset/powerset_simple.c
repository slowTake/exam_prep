#include <stdio.h>
#include <stdlib.h>

/**
 * Prints the current combination found in the result buffer.
 * Ensures there is no trailing space at the end of the line.
 */
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

/**
 * Recursive solver using the Binary Choice pattern:
 * For every number, we either "Keep" it or "Skip" it.
 */
void solve(int target, int *subset, int *res, int size, int idx, int res_len, int current_sum)
{
    // 1. SUCCESS: The current sum exactly matches the target
    if (current_sum == target)
    {
        print_sol(res, res_len);
        return;
    }

    // 2. FAILURE: We've gone over the target or run out of numbers to check
    // Note: 'current_sum > target' only works if all input numbers are positive.
    if (idx == size || current_sum > target)
        return;

    // --- CHOICE A: KEEP the current number ---
    // Place the number in the next available slot in our result buffer
    res[res_len] = subset[idx];
    solve(target, subset, res, size, idx + 1, res_len + 1, current_sum + subset[idx]);

    // --- CHOICE B: SKIP the current number ---
    // We move to the next index but do NOT increment res_len or current_sum
    solve(target, subset, res, size, idx + 1, res_len, current_sum);
}

int main(int argc, char **argv)
{
    // We need at least the target and one number (argc >= 3)
    if (argc < 3)
        return (0);

    int target = atoi(argv[1]);
    int size = argc - 2;

    int *subset = malloc(sizeof(int) * size);
    int *res = malloc(sizeof(int) * size);

    if (!subset || !res)
        return (1);

    // Fill our input array with the numbers from argv
    for (int i = 0; i < size; i++)
    {
        subset[i] = atoi(argv[i + 2]);
    }

    solve(target, subset, res, size, 0, 0, 0);

    return (0);
}