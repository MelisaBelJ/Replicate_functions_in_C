
void	ft_rev_int_tab(int *tab, int size)
{	
	int	position;
	int	aux;

	position = 0;
	while (position < (size / 2))
	{
		aux = tab[position];
		tab[position] = tab[size - position - 1];
		tab[size - position - 1] = aux;
		position++;
	}
}
