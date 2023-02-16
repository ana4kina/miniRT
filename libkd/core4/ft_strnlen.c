#include "libkd.h"

size_t	kd_strnlen(char const *str, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (str[i] && i < maxlen)
		i++;
	return (i);
}
