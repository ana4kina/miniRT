#include "libkd.h"

char	*kd_strrev(char *str)
{
	char			c;
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = kd_strlen(str) - 1;
	while (start < end)
	{
		c = str[start];
		str[start++] = str[end];
		str[end--] = c;
	}
	return (str);
}
