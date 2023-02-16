#include "libkd.h"

int	kd_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
