#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void solve(int n, int *subset, int len)
{
    int i = 1;
    int count = 0;

    // if(n == 0)
    //     printf("\n");

    while(len > i)
    {
        if(subset[i] == n)
        {
            printf("%d\n", subset[i]);
            i++;
        }
        int j = i + 1;
        while(len > j)
        {
            int k = j + 1;
            if(subset[i] + subset[j] == n)
            {
                printf("%d %d\n", subset[i], subset[j]);
                count++;
            }
            while(len > k)
            {
                int l = k + 1;
                if(subset[k] + subset[i] + subset[j] == n)
                {
                    printf("%d %d %d\n", subset[i], subset[j], subset[k]);
                    count++;
                }
                while(len > l)
                {
                    int m = l + 1;
                    if(subset[k] + subset[i] + subset[j] + subset[l] == n)
                    {
                        printf("%d %d %d %d\n", subset[i], subset[j], subset[k], subset[l]);
                        count++;
                    }
                    while(len > m)
                    {
                         if(subset[k] + subset[i] + subset[j] + subset[l] + subset[m] == n)
                         {
                             printf("%d %d %d %d %d\n", subset[i], subset[j], subset[k], subset[l], subset[m]);
                            count++;
                         }
                        m++;
                    }
                    l++;
                }
                k++;
            }
            j++;
        }
        i++;
    }
    if(count == 0)
        printf("\n");
}

int main(int argc, char **argv)
{
    if(argc >= 2 && argv[1][0])
    {
        int j = 0;
        int i = 1;
        int subset[10000] = {0};
        while(argv[i])
        {
            subset[j] = atoi(argv[i]);
            i++;
            j++;
        }
        solve(atoi(argv[1]), subset, j);
    }
    // if(argc == 2 && argv[1][0])
    //     printf("\n");
}
