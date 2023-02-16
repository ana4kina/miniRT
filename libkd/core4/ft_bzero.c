#include "libkd.h"

void	kd_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(unsigned char *)s++ = (unsigned char)0;
}
