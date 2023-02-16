#include "libkd.h"

int	kd_putendl(char *s)
{
	return (kd_putendl_fd(s, 1));
}
