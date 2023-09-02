#include"ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*new_element;

	new_element = malloc(sizeof(t_btree));
	if (new_element == NUL)
		return (NULL);
	new_element->item = item;
	new_element->left = NULL;
	new_element->right = NULL;
	return (new_element);

}