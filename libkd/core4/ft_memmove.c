#include "libkd.h"

void	*kd_memmove(void *dst, void const *src, size_t n)
{
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (n-- > 0)
			((char *)dst)[n] = ((char *)src)[n];
		return (dst);
	}
	return (kd_memcpy(dst, src, n));
}
