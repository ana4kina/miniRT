#include "libkd.h"

int	kd_strncmp(char const *s1, char const *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n > 0 && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
