#include "libkd.h"

int	kd_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
