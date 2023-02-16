#include "libkd.h"

int	kd_putendl_fd(char *s, int fd)
{
	int	i;

	i = kd_putstr_fd(s, fd);
	if (i < 0)
		return (i);
	if (kd_putchar_fd('\n', fd) < 0)
		return (-1);
	return (i + 1);
}
