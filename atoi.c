
int is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' 
		|| c == '\v')
		return (1);
	else
		return  (0);
}

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
