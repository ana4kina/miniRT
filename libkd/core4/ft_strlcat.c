#include "libkd.h"

size_t	kd_strlcat(char *dst, char const *src, size_t dstsize)
{
	unsigned int	len;

	len = kd_strnlen(dst, dstsize);
	return (len + kd_strlcpy(dst + len, src, dstsize - len));
}
