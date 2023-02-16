#include "libkd.h"

void	*kd_memccpy(void *dst, void const *src, int c, size_t n)
{
	void			*chr;
	unsigned int	i;

	chr = kd_memchr(src, c, n);
	if (dst == src)
		return (chr);
	i = 0;
	if (chr)
	{
		while (src + i++ != chr)
			((char *)dst)[i - 1] = ((char *)src)[i - 1];
		((char *)dst)[i - 1] = ((char *)src)[i - 1];
		return (dst + i);
	}
	else
	{
		while (i++ < n)
			((char *)dst)[i - 1] = ((char *)src)[i - 1];
		return (NULL);
	}
}
