#include"ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root != NULL)
	{
		btree_apply_prefix(root->left, applyf);
		btree_apply_prefix(root->right, applyf);
		(*applyf)(root->item);
	}
}