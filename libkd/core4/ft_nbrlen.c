#include "libkd.h"

int	kd_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n && ++i)
		n /= 10;
	return (i);
}
