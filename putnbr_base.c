#include<unistd.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	num_base;

	num_base = ft_strlen(base);
	if (nb == -2147483648)
	{
		write(1, '-', 1);
		ft_putnbr_base(2147483648, base);
	}
	if (nbr < 0)
	{
		write(1, '-', 1);
		nbr = - nbr;
	}
	if (nbr >= num_base)
	{
		ft_putnbr_base(nbr / num_base, base);
		nbr = nbr % num_base;
	}
	write(1, &base[nbr], 1);
}
