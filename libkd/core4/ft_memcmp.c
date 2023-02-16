#include "libkd.h"

int	kd_memcmp(void const *s1, void const *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n > 0 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
