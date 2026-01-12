#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



void solve(int row, int col, int **board, int n, int *res)
{

}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		int n = atoi(argv[1]);

		int **board = calloc(1, sizeof(int *) * n);

		int i = 0;

		while(n > i)
		{
			board[i] = calloc(1, sizeof(int) * n);
			i++;
		}
		int *res = malloc(sizeof(int) * n);

		for(int j = 0; n > j; j++)
			res[j] = -1;
		solve(0, 0, board, n, res);
	}
}
