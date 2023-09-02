
char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	if (!*to_find)
		return (str);
	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[j + i] == to_find[j])
			if (!to_find[++j])
				return (str + i);
	}
	return (0);
}
