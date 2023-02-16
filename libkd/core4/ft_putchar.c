#include "libkd.h"

int	kd_putchar(char c)
{
	return (kd_putchar_fd(c, 1));
}
