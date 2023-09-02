#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	if (begin_list != NULL)
	{
		(*free_fct)(begin_list->data);
		ft_list_clear(begin_list->next, free_fct);
		free(begin_list);
	}
}
/*
#include <stdio.h>
char	*ft_strcpy(char *dest, char *src)
{
	int	length;

	length = 0;
	while (src[length])
	{
		dest[length] = src[length];
		length++;
	}
	dest[length] = '\0';
	return (dest);
}
char	*ft_strdup(char *src)
{
	char	*ptr;
	int		length;

	length = 0;
	while (src[length])
		length++;
	ptr = (char *)malloc (length + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, src);
	return (ptr);
}
t_list	*ft_create_elem(void *data)
{
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	if (l == NULL)
		return (NULL);
	l->next = NULL;
	l->data = data;
	return (l);
}
void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_element;

	new_element = ft_create_elem(data);
	new_element->next = *begin_list;
	*begin_list = new_element;
}
t_list	*ft_list_push_strs(int size, char **strs)
{
	int i;
    t_list *my_list;

	i = 0;
	my_list = NULL;
	while(i < size)
	{
		ft_list_push_front(&my_list, ft_strdup(strs[i]));
		i++;
	}
	return (my_list);
}
int main(int na, char **args) {
    t_list *my_list = NULL; 

    my_list = ft_list_push_strs(na, args);
    ft_list_clear(my_list, &free);
    system("leaks a.out");
    return 0;
}*/