#include <unistd.h>

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			nb = nb % 10;
		}
		write(1, &(char){nb + '0'}, 1);
	}
}
