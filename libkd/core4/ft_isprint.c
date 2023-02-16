#include "libkd.h"

int	kd_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
