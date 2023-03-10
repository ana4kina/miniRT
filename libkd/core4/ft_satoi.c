#include "libkd.h"

int	kd_satoi(char const *str, int *n)
{
	short	u;
	long	ln;

	if (!str)
		return (-1);
	u = 1;
	ln = 0;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			u = -1;
	while (kd_isdigit(*str))
		ln = ln * 10 + *str++ - '0';
	ln *= u;
	if (*str || ln < INT_MIN || ln > INT_MAX)
		return (-1);
	*n = ln;
	return (0);
}
