#include "libkd.h"

char	*kd_strcpy(char *dest, char const *src)
{
	kd_stpcpy(dest, src);
	return (dest);
}
