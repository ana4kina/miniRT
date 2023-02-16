#include "libkd.h"

void	*kd_memchr(void const *s, int c, size_t n)
{
	while (n-- > 0)
		if (*(unsigned char *)s++ == (unsigned char)c)
			return ((void *)--s);
	return (NULL);
}
