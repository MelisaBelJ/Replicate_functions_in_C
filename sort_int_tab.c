
void	ft_sort_int_tab(int *tab, int size)
{
	int	counter;
	int	inside_counter;
	int	aux;

	counter = 0;
	while (counter < size)
	{
		inside_counter = 0;
		while (inside_counter < size - counter - 1)
		{
			if (tab[inside_counter] > tab[inside_counter + 1])
			{
				aux = tab[inside_counter];
				tab[inside_counter] = tab[inside_counter + 1];
				tab[inside_counter + 1] = aux;
			}			
			inside_counter++;
		}
		counter++;
	}
}
