#include "ft_tail.h"

int	ft_atoi(char *str)
{
	int	nb;
	int	sign;
	int	pos;

	nb = 0;
	sign = 1;
	pos = 0;
	while (is_space(str[pos]))
		pos++;
	while (str[pos] == '-' || str[pos] == '+')
	{
		if (str[pos] == '-')
			sign *= -1;
		pos++;
	}
	while (str[pos] && (str[pos] >= '0' && str[pos] <= '9'))
	{
		nb = nb * 10 + str[pos] - '0';
		pos++;
	}
	return (sign * nb);
}

int	ft_str_is_numeric(char *str)
{
	int	result;
	int	position;

	result = 1;
	position = 0;
	while (str[position] && result == 1)
	{
		if (str[position] >= '0' && str[position] <= '9')
			result = 1;
		else
			result = 0;
		position++;
	}
	return (result);
}

int	get_initial(char **args, int *is_c, int *num, int na)
{
	int	i;

	i = 1;
	*is_c = 0;
	*num = 10;
	if (args[i][0] == '-' && args[i][1] == 'c' && na > 2)
	{
		*is_c = 1;
		if (args[i++][2] == '\0' && na > 3)
		{
			if (ft_str_is_numeric(args[i]))
				*num = ft_atoi(args[i]);
			else
				*num = -1;
		}
		else
		{
			if (ft_str_is_numeric(args[i] + 2))
				*num = ft_atoi(args[i] + 2);
			else
				*num = -1;
		}
		i++;
	}
	return (i);
}

void	ft_print(int na, char **args, int i, int init)
{
	if (na != (init + 1))
	{
		if (i >= (init + 1))
			write(1, "\n", 1);
		write(1, "==> ", 4);
		write(1, basename(args[i]), ft_strlen(basename(args[i])));
		write(1, " <==\n", 5);
	}
}

int	main(int na, char **args)
{
	int	i;
	int	num;
	int	is_c;
	int	init;

	if (na < 2)
		write(2, "File name missing\n", 18);
	else
	{
		init = get_initial(args, &is_c, &num, na);
		if (num == -1)
			write(2, "usage: ft_tail -c # [file ...]\n", 31);
		else
		{
			i = init;
			while (i < na)
			{
				ft_print(na, args, i, init);
				read_file(args[i], count_lines(args[i], is_c) - num, is_c);
				i++;
			}		
		}
	}
	return (0);
}
