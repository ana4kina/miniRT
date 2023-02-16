#include "libkd.h"

void	*kd_calloc(size_t count, size_t size)
{
	void	*p;

	p = kd_malloc(count * size);
	if (!p)
		return (p);
	kd_bzero(p, count * size);
	return (p);
}
