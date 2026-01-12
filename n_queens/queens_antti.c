#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_result(int *res, int len)
{
	int i = 0;

	while(len > i)
	{
		printf("%d", res[i]);
		if(len - 1 > i )
			printf(" ");
		i++;
	}
	printf("\n");
}

int result_found(int *res, int len)
{
	int i = 0;

	while(len > i)
	{
		if(res[i] == -1)
			return(0);
		i++;
	}
	return(1);
}

int safe_dia(int row, int col, int **board, int len)
{
	int x = row;
	int y = col;

	//south east
	while(len > y && len > x)
	{
		if(board[x][y] != 0)
			return 0;
		x++;
		y++;
	}
	
	x = row;
	y = col;
	//north east
	while(0 <= y && len > x)
	{
		if(board[x][y] != 0)
			return 0;
		x++;
		y--;
	}

	x = row;
	y = col;
	//north west
	while(0 <= y && 0 <= x)
	{
		if(board[x][y] != 0)
			return 0;
		x--;
		y--;
	}

	x = row;
	y = col;	
	//south west
	while(len > y && 0 <= x)
	{
		if(board[x][y] != 0)
			return 0;
		y++;
		x--;
	}
	return 1;
}

int safe_row_col(int row, int col, int **board, int len)
{
	int i = 0;
	while(len > i)
	{
		if(board[row][i] != 0)
			return 0;
		i++;
	}

	i = 0;
	while(len > i)
	{
		if(board[i][col])
			return 0;
		i++;
	}
	return 1;
}

int is_safe(int row, int col, int **board, int len)
{
	if(!safe_row_col(row, col, board, len))
		return 0;
	if(!safe_dia(row, col, board, len))
		return 0;
	return 1;
}

void solve(int row, int col, int **board, int n, int *res)
{
	if(result_found(res, n))
	{
		print_result(res, n);
			return;
	}

	if(col >= n || row >= n)
		return;

	while(n > col)
	{
		if(is_safe(row, col, board, n))
		{
			res[row] = col;
			board[row][col] = 1;
			solve(row + 1, 0, board, n, res);
			res[row] = -1;
			board[row][col] = 0;
		}
		col++;
	} 
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		int n = atoi(argv[1]);
		int **board = calloc(1, sizeof(int *) * n);
		
		int i = 0;
		while(i < n)
		{
			board[i] = calloc(1, sizeof(int) * n);
			i++;
		}
		int *res = malloc(sizeof(int) * n);

		for(int j = 0; j < n; j++)
			res[j] = -1;
		solve(0, 0, board, n, res);
	}
}