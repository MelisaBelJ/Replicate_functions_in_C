#include<unistd.h>

int	is_valid(int *board, int n)
{
	int	valid;
	int	i;
	int	j;

	valid = 1;
	i = 0;
	while (valid && i < n)
	{
		j = i + 1;
		while (valid && j < n)
		{
			if ((board[i] == board[j]) || (board[i] + j - i == board[j])
				|| (board[i] + i - j == board[j]))
				valid = 0;
			j++;
		}
		i++;
	}
	return (valid);
}

void	print_board(int *board)
{
	int	pos;

	if (is_valid(board, 10))
	{
		board[10]++;
		pos = 0;
		while (pos < 10)
		{
			write(1, &(char){board[pos] + '0'}, 1);
			pos++;
		}
		write(1, "\n", 1);
	}
}

void	permute(int *board, int pos)
{
	int	value;

	if (pos < 10)
	{
		value = 0;
		while (value < 10)
		{
			board[pos] = value;
			if (is_valid(board, pos + 1))
				permute(board, pos + 1);
			value++;
		}
	}
	else
	{
		print_board(board);
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[11];

	board[10] = 0;
	permute(board, 0);
	return (board[10]);
}
