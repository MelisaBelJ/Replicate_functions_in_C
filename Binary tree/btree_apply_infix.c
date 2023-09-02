#include"ft_btree.h"

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root != NULL)
	{
		btree_apply_prefix(root->left, applyf);
		(*applyf)(root->item);
		btree_apply_prefix(root->right, applyf);
	}
}