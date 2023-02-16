#include "libkd.h"

int	kd_putstr(char *s)
{
	return (kd_putstr_fd(s, 1));
}
