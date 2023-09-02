
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				result;
	unsigned int	position;

	result = 90;
	position = 0;
	while (result == 90 && position < n)
	{
		if (s1[position] < s2[position])
			result = -1;
		else if (s1[position] > s2[position])
			result = 1;
		else if (s1[position] == '\0' && s2[position] == '\0')
			result = 0;
		position++;
	}
	if (result == 90)
		result = 0;
	return (result);
}
