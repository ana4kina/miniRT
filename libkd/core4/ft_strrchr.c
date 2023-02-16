#include "libkd.h"

char	*kd_strrchr(char const *s, int c)
{
	unsigned int	i;

	i = kd_strlen(s) + 1;
	while (i-- > 0)
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	return (0);
}
