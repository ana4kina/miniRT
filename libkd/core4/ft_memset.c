#include "libkd.h"

void	*kd_memset(void *b, int c, size_t len)
{
	void	*p;

	p = b;
	while (len-- > 0)
		*(unsigned char *)b++ = (unsigned char)c;
	return (p);
}
