#include "ft_list.h"
#include <stdlib.h>

int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*new_element;

	new_element = begin_list;
	i = 0;
	while (new_element != NULL)
	{
		i++;
		new_element = new_element->next;
	}
	return (i);
}
/*
#include <stdio.h>
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
int main() {
    t_list *my_list = NULL; // Initialize an empty linked list
    
    // Add some elements to the front of the list
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;
    int data4 = 40;

    ft_list_push_front(&my_list, &data1);
    ft_list_push_front(&my_list, &data2);
    ft_list_push_front(&my_list, &data3);
        printf("%d ", ft_list_size(my_list));

    // Don't forget to free the memory when you're done
    // (You should have a function for this, e.g., ft_list_clear)

    return 0;
}*/