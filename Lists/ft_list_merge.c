#include "ft_list.h"

void	ft_list_merge(t_list **begin_list, t_list *begin_list2)
{
	t_list	*aux;

	if (begin_list == NULL || *begin_list == NULL)
		*begin_list = begin_list2;
	else
	{
		aux = *begin_list;
		while (aux->next)
			aux = aux->next;
		aux->next = begin_list2;
	}
}
