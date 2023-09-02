#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <string.h>
#include <libgen.h>

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
	write(2, "cat: ", 5);
	write(2, basename(name), ft_strlen(basename(name)));
	write(2, ": ", 2);
	while (*msg)
		write(2, msg++, 1);
	write(2, "\n", 1);
}

void	read_file(char *name)
{
	char	buffer;
	int		fd;

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
			while (read(fd, &buffer, 1))
				write(1, &buffer, 1);
		}
	}
}

int	main(int na, char **args)
{
	int		i;

	if (na < 2)
		write(2, "File name missing\n", 18);
	else
	{
		i = 1;
		while (i < na)
			read_file(args[i++]);
	}
	return (0);
}
