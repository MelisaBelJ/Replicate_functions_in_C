#include"ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
		int (*cmpf)(void *, void *))
{
	t_btree	*current;

	if (root != NULL && item != NULL)
	{
		current = *root;
		if (current == NULL)
			*root = btree_create_node(item);
		if ((*cmpf)(item, current->item) < 0)
			btree_insert_data(&current->left, item, cmpf);
		else
			btree_insert_data(&current->right, item, cmpf);
	}
}
