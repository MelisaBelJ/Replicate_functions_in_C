
int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	pos;

	pos = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[pos] && pos < (size - 1))
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] == '\0';
	return (ft_strlen(src));
}
