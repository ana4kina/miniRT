#include "libkd.h"

size_t	kd_strlcpy(char *dst, char const *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		if (i + 1 < dstsize)
			dst[i] = src[i];
		i++;
	}
	if (i + 1 < dstsize)
		dstsize = i + 1;
	if (dstsize > 0)
		dst[dstsize - 1] = 0;
	return (i);
}
