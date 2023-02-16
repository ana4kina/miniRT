#include "libkd.h"

char	*kd_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 && s2)
		return (kd_strdup(s2));
	else if (s1 && !s2)
		return (kd_strdup(s1));
	else if (!s1 && !s2)
		return (kd_strdup(""));
	str = kd_malloc(sizeof(char) * (kd_strlen(s1) + kd_strlen(s2) + 1));
	if (!str)
		return (str);
	kd_stpcpy(kd_stpcpy(str, s1), s2);
	return (str);
}
