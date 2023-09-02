#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	**return;
	t_list	*current;
	t_list	*next;

	return = begin_list;
	current= 0;
	while (*begin_list != NULL)
	{
		next = (*begin_list)->next;
		(*begin_list)->next = current;
		current= *begin_list;
		*begin_list = next;
	}
	*return = current;
}