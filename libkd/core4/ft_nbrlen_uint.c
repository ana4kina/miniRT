#include "libkd.h"

int	kd_nbrlen_uint(unsigned int n)
{
	int	i;

	i = 0;
	while (n && ++i)
		n /= 10;
	return (i);
}
