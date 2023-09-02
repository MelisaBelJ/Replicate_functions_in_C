#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	if (begin_list != NULL)
	{
		(*free_fct)(begin_list->data);
		free(begin_list);
	}
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list *list_ptr:
	t_list *aux:

	list_ptr = begin_list;
	while (list_ptr != NULL)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
		{
			aux = list_ptr;
			ft_list_clear(aux);
		}
		list_ptr = list_ptr->next;
	}
}