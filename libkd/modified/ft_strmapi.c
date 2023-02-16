#include "libkd.h"

char	*kd_strmapi(char const *src, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!src)
		return (kd_strdup(""));
	str = kd_malloc(sizeof(char) * (kd_strlen(src) + 1));
	if (!str)
		return (str);
	i = 0;
	while (src[i])
	{
		str[i] = (*f)(i, src[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
