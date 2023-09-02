#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str);

int	ft_atoi_base(char *str, char *base);

int	min_pow(int nbr, int base_len)
{
	int	result;
	int	power;

	result = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		result++;
	}
	else if (nbr == 0)
		return (1);
	power = 1;
	while (power <= nbr)
	{
		power *= base_len;
		result++;
	}
	return (result);
}

int	ft_geti_base(int n, char *str, int base_len, char *base)
{
	int	pos;

	if (n < 0)
	{
		pos = ft_geti_base(-(n / base_len), str, base_len, base);
		str[pos] = base [-(n + base_len) % base_len];
		return (pos + 1);
	}
	if (n < base_len)
	{
		str[0] = base[n];
		return (1);
	}
	else
	{
		pos = ft_geti_base(n / base_len, str, base_len, base);
		str[pos] = base [n % base_len];
		return (pos + 1);
	}
}

char	*ft_itoa_base(int nbr, char *base)
{
	char	*result;
	int		pos;
	int		base_len;
	char	*aux;

	base_len = ft_strlen(base);
	result = (char *)malloc (min_pow(nbr, base_len));
	pos = 0;
	if (!result)
		return (0);
	if (nbr == -2147483648)
	{
		result[pos] = '-';
	}
	if (nbr < 0)
	{
		nbr *= -1;
		result[pos] = '-';
		pos++;
	}
	aux = result + pos;
	pos = ft_geti_base(nbr, aux, base_len, base);
	aux[pos] = '\0';
	return (result);
}

int	valid_base(char *base)
{
	int	counter;
	int	inner_counter;
	int	valid;

	valid = 1;
	if (ft_strlen(base) < 2)
		valid = 0;
	counter = 0;
	while (base[counter])
	{
		if (base[counter] == '-' || base[counter] == '+'
			|| base[counter] <= 32 || base[counter] == 127)
			valid = 0;
		inner_counter = counter + 1;
		while (base[inner_counter])
		{
			if (base[counter] == base[inner_counter])
				valid = 0;
			inner_counter++;
		}
		counter++;
	}
	return (valid);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (valid_base(base_from) && valid_base(base_to))
	{
		return (ft_itoa_base(ft_atoi_base(nbr, base_from), base_to));
	}
	else
	{
		return (0);
	}
}
