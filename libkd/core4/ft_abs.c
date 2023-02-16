#include "libkd.h"

unsigned int	kd_abs(int n)
{
	if (n == -2147483648)
		return (2147483648);
	if (n < 0)
		return (n * -1);
	return (n);
}
