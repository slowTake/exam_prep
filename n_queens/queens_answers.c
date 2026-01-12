#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int is_safe(int row, int col, int *board)
{
	int i = 0; 
	
	while(col > i)
	{
		int prev_row = board[i];
		int prev_col = i;

		if(prev_row == row)
			return 0;
		
		int row_dif = abs(prev_row - row);
		int col_dif = col - prev_col;
		if(row_dif == col_dif)
			return 0;
		i++;
	}
	return 1;
}

void solve(int col, int n, int *board)
{
	if(col == n)
	{
		int i = 0;

		while(n > i)
		{
			if(i == n -1)
				printf("%d", board[i]);
			else
				printf("%d ", board[i]);
			i++;
		}
		printf("\n");
		return;
	}
	int row = 0;

	while(n > row)
	{
		if(is_safe(row, col, board))
		{
			board[col] = row;
			solve(col + 1, n, board);
		}
		row++;
	}
}


int main(int argc, char **argv)
{
	if(argc == 2)
	{
		int n = atoi(argv[1]);

		if(n <= 0)
			return 0;
		int *board = malloc(sizeof(int) * n);
		if(!board)
			return(1);
		solve(0, n, board);

		free(board);
		return (0);
	}
}