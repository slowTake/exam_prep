#include <unistd.h>
#include <stdio.h> // Allowed for 'puts'

// 1. Check if the string is balanced (ignoring spaces)
int is_balanced(char *str)
{
    int count = 0;
    int i = 0;
    while (str[i])
    {
        if (str[i] == '(')
            count++;
        else if (str[i] == ')')
            count--;
        // If count is negative, there are more ')' than '(' at this point
        if (count < 0)
            return (0);
        i++;
    }
    return (count == 0);
}

// 2. The Recursive Backtracking function
void solve(char *str, int index, int remL, int remR)
{
    // Base Case: We have reached the end of the string
    if (str[index] == '\0')
    {
        // Only print if we've removed exactly the required amount AND it's balanced
        if (remL == 0 && remR == 0 && is_balanced(str))
            puts(str);
        return;
    }

    char backup = str[index];

    // OPTION 1: Try removing the character (if it's a parenthesis and we need to remove more)
    if (backup == '(' && remL > 0)
    {
        str[index] = ' ';
        solve(str, index + 1, remL - 1, remR);
        str[index] = backup; // Backtrack: put the '(' back for the next recursive branch
    }
    else if (backup == ')' && remR > 0)
    {
        str[index] = ' ';
        solve(str, index + 1, remL, remR - 1);
        str[index] = backup; // Backtrack: put the ')' back
    }

    // OPTION 2: Keep the character and move to the next index
    solve(str, index + 1, remL, remR);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        char *str = argv[1];
        int minL = 0;
        int minR = 0;
        int i = 0;

        // Step 1: Calculate the minimum characters that MUST be removed
        while (str[i])
        {
            if (str[i] == '(')
                minL++;
            else if (str[i] == ')')
            {
                if (minL > 0)
                    minL--; // A '(' matches this ')'
                else
                    minR++; // Unmatched ')'
            }
            i++;
        }
        // Step 2: Start the recursion
        solve(str, 0, minL, minR);
    }
    return (0);
}