#include "libkd.h"

int	kd_ptrcmp(void *p1, void *p2)
{
	if (p1 == p2)
		return (0);
	if (p1 > p2)
		return (1);
	return (-1);
}
