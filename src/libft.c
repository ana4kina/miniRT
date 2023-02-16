#include "minirt.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && *s++)
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar_fd(*s++, fd);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	check_endline(char **str, int *err)
{
	while (ft_isspace(**str))
		(*str)++;
	if (**str != '\0' && check_identyfier(*str, "raiiinbow"))
		*err = 1;
}

