
char	*ft_strcat(char *dest, char *src)
{
	int	position;
	int	position2;

	position = 0;
	position2 = 0;
	while (dest[position])
		position++;
	while (src[position2])
	{
		dest[position + position2] = src[position2];
		position2++;
	}
	dest[position + position2] = '\0';
	return (dest);
}
