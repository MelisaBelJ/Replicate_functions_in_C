#include <stdlib.h>

int	c_in_str(char c, char *charset)
{
	int	i;

	i = -1;
	if (!charset[0])
		return (!c);
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (!c);
}

char	*ft_strcpy(char *str, char *charset, int *word_len)
{
	int		l;
	char	*dest;

	l = 0;
	while (str[l] && !c_in_str(*(str + l), charset))
		l++;
	dest = (char *)malloc (sizeof(char) * (l + 1));
	*word_len = l;
	if (dest == NULL)
		return (NULL);
	l = 0;
	while (str[l] && !c_in_str(str[l], charset))
	{
		dest[l] = str[l];
		l++;
	}
	dest[l] = '\0';
	return (dest);
}

int	get_w_c(char *str, char *charset)
{
	int	total_words;

	total_words = 0;
	while (*str)
	{
		if (!c_in_str(*str, charset))
		{
			total_words++;
			while (*str && !c_in_str(*str, charset))
				str++;
		}
		else if (!c_in_str(*str, charset))
			str++;
		while (*str && c_in_str(*str, charset))
			str++;
	}
	return (total_words);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		total_words;
	int		i;
	int		n;

	n = get_w_c(str, charset);
	res = (char **)malloc (sizeof(char *) * (n + 1));
	if (res == NULL)
		return (NULL);
	total_words = 0;
	i = 0;
	while (*str && total_words < n)
	{
		if (c_in_str(*str, charset))
			str++;
		else
		{
			res[total_words] = ft_strcpy(str, charset, &i);
			str += i;
			total_words++;
		}
	}
	res[total_words] = NULL;
	return (res);
}
/*
#include<stdio.h>
int main() {
    char *str = "This is a test string,split it";
    char *charset = "\0"; // You can customize the charset as needed

    char **result = ft_split(str, charset);

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Print the split strings
    int i = 0;
    while (result[i]) {
        printf("%s\n", result[i]);
        free(result[i]); // Free the allocated memory for each string
        i++;
    }

    // Free the array of strings and the result itself
    free(result);

    return 0;
}*/
