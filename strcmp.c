
int	ft_strcmp(char *s1, char *s2)
{
	int	result;
	int	position;

	result = 90;
	position = 0;
	while (result == 90)
	{
		if (s1[position] != s2[position])
			result = s1[position] - s2[position];
		else if (s1[position] == '\0' && s2[position] == '\0')
			result = 0;
		position++;
	}
	return (result);
}
