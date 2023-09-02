#include "ft_list.h"
#include <stdlib.h>

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
/*
#include <stdio.h>
int main() {
    t_list *my_list = NULL; // Initialize an empty linked list
    
    // Add some elements to the front of the list
    int data1 = 10;
    int data2 = 20;
    int data3 = 30;

    ft_list_push_front(&my_list, &data1);
    ft_list_push_front(&my_list, &data2);
    ft_list_push_front(&my_list, &data3);

    // Traverse and print the elements of the list
    t_list *current = my_list;
    while (current != NULL) {
        int *data = (int *)current->data;
        printf("%d ", *data);
        current = current->next;
    }

    // Don't forget to free the memory when you're done
    // (You should have a function for this, e.g., ft_list_clear)

    return 0;
}*/