#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	get_size(char **strs, int size, char *sep)
{
	int	pos;
	int	length;

	pos = 0;
	length = 0;
	while (pos < size)
	{
		length += ft_strlen(strs[pos]);
		pos++;
	}
	return (length + (size - 1) * ft_strlen(sep) + 1);
}

char	*ft_strcat(char *dest, char *src)
{
	int	len_dest;
	int	pos_src;

	len_dest = ft_strlen(dest);
	pos_src = 0;
	while (src[pos_src])
	{
		dest[len_dest + pos_src] = src[pos_src];
		pos_src++;
	}
	dest[len_dest + pos_src] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		pos;
	char	*str;

	if (size <= 0)
	{
		str = malloc(1);
		*str = '\0';
		return (str);
	}
	str = malloc(get_size(strs, size, sep));
	if (str == NULL)
		return (NULL);
	*str = 0;
	pos = 0;
	while (pos < size)
	{
		if (pos > 0)
			ft_strcat(str, sep);
		ft_strcat(str, strs[pos]);
		pos++;
	}
	return (str);
}
