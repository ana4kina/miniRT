#include "libkd.h"

int	kd_toupper(int c)
{
	if (kd_islower(c))
		return (c - 32);
	return (c);
}
