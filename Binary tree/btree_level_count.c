#include"ft_btree.h"

int	max(int a, int b)
{
	int	max;

	max = a;
	if (b>a)
		max = b;
	return(max);
}

int	btree_level_count(t_btree *root)
{
	int	i;
	i = 0;
	if (root != NULL)
		i = 1;
	i += max(btree_level_count(root->left), btree_level_count(root->left));
	return (i);
}