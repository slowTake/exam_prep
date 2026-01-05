#include <stdio.h>
#include <unistd.h>

// Simple bubble sort to ensure we start in alphabetical order
void ft_sort(char *s, int len)
{
    int i = 0, j;
    char tmp;
    while (i < len)
    {
        j = i + 1;
        while (j < len)
        {
            if (s[i] > s[j])
            {
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

void solve(char *str, char *res, int *used, int pos, int len)
{
    int i = 0;

    // Base case: If we've filled the result string to the required length
    if (pos == len)
    {
        res[pos] = '\0';
        puts(res); // Automatically prints the string followed by a newline
        return;
    }

    // Try every character from the sorted string
    while (i < len)
    {
        if (!used[i])
        {
            used[i] = 1;       // Mark this specific character as "busy"
            res[pos] = str[i];  // Place it at the current position
            solve(str, res, used, pos + 1, len); // Move to the next position
            used[i] = 0;       // Backtrack: Free the character for other branches
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0])
    {
        int len = 0;
        char res[100];      // Buffer to build the permutation
        int used[100] = {0}; // Tracking array (all initialized to 0)

        while (argv[1][len])
            len++;

        ft_sort(argv[1], len);
        solve(argv[1], res, used, 0, len);
    }
    return (0);
}