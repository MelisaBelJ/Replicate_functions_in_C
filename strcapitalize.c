
char	*ft_strcapitalize(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		if (str[pos] >= 'A' && str[pos] <= 'Z')
			str[pos] += 32;
		if (str[pos] >= 'a' && str[pos] <= 'z')
		{
			if (!(str[pos - 1] >= 'a' && str[pos - 1] <= 'z'))
			{
				if (!(str[pos - 1] >= '0' && str[pos - 1] <= '9'))
				{
					if (!(str[pos - 1] <= 'Z' && str[pos - 1] >= 'A'))
						str[pos] -= 32;
				}
			}
			else if (pos == 0)
				str[pos] -= 32;
		}
		pos++;
	}
	return (str);
}
