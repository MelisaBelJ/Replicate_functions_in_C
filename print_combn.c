#include <unistd.h>

void	ft_print_comb(char *digits, int i, int j, int n)
{
	int	counter;

	if (i < n)
	{
		counter = j;
		while (counter < 10)
		{
			digits[i] = counter + '0';
			counter++;
			ft_print_comb(digits, i + 1, counter, n);
		}
	}
	else
	{
		write(1, ", ", digits[9]);
		if (digits[9] == 0)
			digits[9] = 2;
		write(1, digits, n);
	}
}

void	ft_print_combn(int n)
{
	char	digits[10];

	digits[9] = 0;
	ft_print_comb(digits, 0, 0, n);
}
