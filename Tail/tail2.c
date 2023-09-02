#include "ft_tail.h"

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

void	ft_error(char *name, char *msg)
{
	write(2, "ft_tail: ", 9);
	write(2, basename(name), ft_strlen(name));
	write(2, ": ", 2);
	while (*msg)
		write(2, msg++, 1);
	write(2, "\n", 1);
}

int	count_lines(char *name, int no_lines)
{
	char	buffer;
	int		fd;
	int		i;

	if (basename(name)[0] == '/')
	{
		ft_error(name, ": Is a directory");
	}
	else
	{
		fd = open(name, O_RDONLY);
		if (fd < 0)
			ft_error(name, strerror(errno));
		else
		{
			i = 0;
			while (read(fd, &buffer, 1))
				if (buffer == '\n' || no_lines)
					i++;
			return (i);
		}
	}
	return (-1);
}

void	read_file(char *name, int m, int no_lines)
{
	char	buffer;
	int		fd;
	int		i;

	if (m > 0)
	{
		fd = open(name, O_RDONLY);
		if (fd < 0)
			ft_error(name, strerror(errno));
		else
		{
			i = 0;
			while (read(fd, &buffer, 1))
			{
				if (i >= m)
					write(1, &buffer, 1);
				if (buffer == '\n' || no_lines)
					i++;
			}
		}
	}
}

int	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	else
		return (0);
}
