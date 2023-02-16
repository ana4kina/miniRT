#include "libkd.h"

char	*kd_strchr(char const *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char *)--s);
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
