#include "libkd.h"

char	*kd_strdup(char const *s)
{
	char	*str;

	if (!s)
		s = "";
	str = kd_malloc(sizeof(char) * (kd_strlen(s) + 1));
	if (!str)
		return (str);
	return (kd_strcpy(str, s));
}
