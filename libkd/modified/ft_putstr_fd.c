#include "libkd.h"

int	kd_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s && s[i])
		if (kd_putchar_fd(s[i++], fd) < 0)
			return (-1);
	return (i);
}
