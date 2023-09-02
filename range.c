#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	pos;

	if (min >= max)
		return (NULL);
	ptr = (int *)malloc ((max - min) * sizeof(int));
	if (ptr == NULL)
		return (NULL);
	pos = 0;
	while (min + pos < max)
	{
		ptr[pos] = min + pos;
		pos++;
	}
	return (ptr);
}
