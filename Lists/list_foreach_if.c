#include "ft_list.h"
#include <stdlib.h>

void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void
 	*data_ref, int (*cmp)())
{
	t_list *list_ptr:

	list_ptr = begin_list;
	while (list_ptr != NULL)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
			(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}