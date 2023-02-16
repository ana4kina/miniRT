#include "libkd.h"

char	*kd_strcat(char *dest, char const *src)
{
	char	*p;

	p = dest;
	while (*dest)
		dest++;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (p);
}
