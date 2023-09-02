{
	char	buffer;
	int		size;
	int		fd;

	size = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("ft_hexdump: ", 1);
		ft_putstr(*file_path, 1);
		ft_putstr(": No such file or directory\n", 1);
	}
	else
		while (read(fd, &buffer, 1) > 0)
			size++;
	close(fd);
	return size;
}

void	print_zeros(int n, int i)
{
	if (n / 16 != 0)
		print_zeros(n / 16, i + 1);
	else if (i < 8)
		write(1, "000000000", 8 - i);
	ft_print_hex(' ', n, 0, 1);
}

void	ft_c_op(char *str, int j)
{
	int	i;

	ft_putstr("|", 0);
	i = j - 1;
	while (++i < 16 + j && str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, str + i, 1);
		else
			ft_putstr(".", 0);
	}
	ft_putstr("|", 0);
}

void	ft_print_hex(char c, int i, int size, int only_one)
{
	int			spaces;
	const char	*base;

	base = "0123456789abcdef";
	spaces = 3;
	if (only_one == 0)
	{
		if (i < size)
		{
			write(1, base + c / 16, 1);
			write(1, base + c % 16, 1);
			spaces = 1;
		}
		if ((i + 1) % 8 == 0)
			spaces++;
		write(1, "               ", spaces);
	}
	else
		write(1, base + i % 16, 1);
}

void	ft_hexdump(char *str, int size, int c_op)
{
	int		i;
	int		j;

	j = 0;
	while (str[j])
	{
		print_zeros(j, 1);
		ft_putstr("  ", 0);
		i = j - 1;
		while (++i < 16 + j)
			ft_print_hex(*(str + i), i, size, 0);
		if (c_op != 0)
			ft_cop(str, j);
		ft_putstr("\n", 0);
		j += 16;
	}
	print_zeros(j, 1);
	ft_putstr("\n", 0);
}

void	ft_begin(char *name, int c_op)
{
	int		size;
	char	*str;
	int		fd;

	size = get_size(name);
	str = malloc(size + 1);
	fd = open(file_path, O_RDONLY);
	read(fd, str, size);
	str[size] = '\0';
	close(fd);
	ft_hexdump(str, size, c_op);
	free(str);
}

int		main(int na, char **args)
{
	int		i;
	int		c_op;

	c_op = 0;
	if (na > 1 && args[1][0] == '-' && args[1][1] == 'C')
		c_op = 1;
	i = 1 + c_op;
	if (na == i)
		ft_putstr("ft_hexdump: usage: [-C] [files]\n", 1);
	while (i < na)
	{
		ft_begin(args[i], c_op);
		i++;
	}
	return 0;
}
