#include <stdio.h>
#include <stdlib.h>

int    ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int    is_safe(int *rows, int row, int pos)
{
    int    i;
    int    r;

    i = 0;
    while (i < pos)
    {
        r = rows[i];
        if (r == row)
            return (0);
        if (ft_abs(row - r) == ft_abs(pos - i))
            return (0);
        i++;
    }
    return (1);
}

void    print_sol(int *rows, int n)
{
    int    i;

    i = 0;
    while (i < n)
    {
        printf("%d", rows[i]);
        if (i < n - 1)
            printf(" ");
        i++;
    }
    printf("\n");
}

void    solve(int *rows, int n, int pos)
{
    int    row;

    if (n == pos)
    {
        print_sol(rows, n);
        return ;
    }
    row = 0;
    while (row < n)
    {
        if (is_safe(rows, row, pos))
        {
            rows[pos] = row;
            solve(rows, n, pos + 1);
        }
        row++;
    }
}

int    main(int ac, char **av)
{
    int n;
    int *rows;

    if (ac != 2)
        return (0);
    n = atoi(av[1]);
    if (n <= 0)
        return (0);
    rows = (int *)malloc(sizeof(int) * n);
    if (!rows)
        return (1);
    solve(rows, n, 0);
    free(rows);
    return (0);
}