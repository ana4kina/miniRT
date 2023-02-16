#include "libkd.h"

void	*kd_memcpy(void *dst, void const *src, size_t n)
{
	unsigned int	i;

	if (dst == src)
		return (dst);
	i = 0;
	while (i++ < n)
		((char *)dst)[i - 1] = ((char *)src)[i - 1];
	return (dst);
}
