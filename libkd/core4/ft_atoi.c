#include "libkd.h"

int	kd_atoi(char const *str)
{
	short	u;
	int		n;

	u = 1;
	n = 0;
	while (kd_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			u = -1;
	while (kd_isdigit(*str))
		n = n * 10 + *str++ - '0';
	return (n * u);
}
