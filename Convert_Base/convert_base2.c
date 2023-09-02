#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	ctoi(char c, char *base)
{
	int	pos;

	pos = 0;
	while (base[pos] && base[pos] != c)
		pos++;
	if (base[pos] == '\0')
		return (-1);
	else
		return (pos);
}

int	init(char *str, int *ptr)
{
	int	sign;

	while (str[*ptr] == '\f' || str[*ptr] == '\t' || str[*ptr] == ' '
		|| str[*ptr] == '\n' || str[*ptr] == '\r' || str[*ptr] == '\v')
		*ptr = *ptr + 1;
	sign = 1;
	while (str[*ptr] == '+' || str[*ptr] == '-')
	{
		if (str[*ptr] == '-')
			sign *= -1;
		*ptr = *ptr + 1;
	}
	return (sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	pos;
	int	aux;

	pos = 0;
	result = 0;
	sign = init(str, &pos);
	while (str[pos])
	{
		aux = ctoi(str[pos], base);
		if (aux == -1)
			return (0);
		result = (ft_strlen(base) * result) + aux;
		pos++;
	}
	return (result * sign);
}
