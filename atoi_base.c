
int is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' 
		|| c == '\v')
		return (1);
	else
		return  (0);
}

int	get_tr(char *base, char c)
{
	int	pos;

	pos = 0;
	while (base[pos] && base[pos] != c)
		pos++;
	if (base[pos] == c)
		return (pos);
	else
		return (-1);
}

int	is_valild(char *str)
{
	int	length;
	int	length2;

	length = 0;
	while (str[length])
	{
		if (str[length] == '+' || length == '-')
			return (0);
		length2 = length + 1;
		while (str[length2])
		{
			if (str[length2] == str[length])
				return (0);
			length2++;
		}
		length++;
	}
	if (length <= 1)
		return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	sign;
	int	pos;
	int	translation;

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
	translation = get_tr(base, str[pos]);
	while (str[pos] && translation != -1 && is_valild(base))
	{
		nb = nb * ft_strlen(base) + translation;
		pos++;
		translation = get_tr(base, str[pos]);
	}
	return (sign * nb);
}
