#include "libkd.h"

char	*kd_stpcpy(char *dest, char const *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (dest);
}
