#include "libkd.h"

static unsigned short	kd_set_check(char const c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*kd_strtrim(char const *src, char const *set)
{
	unsigned int	start;
	unsigned int	end;

	if (!src)
		return (kd_strdup(""));
	else if (!set)
		return (kd_strdup(src));
	start = 0;
	while (src[start] && kd_set_check(src[start], set))
		start++;
	end = kd_strlen(src);
	while (end > 0 && kd_set_check(src[end - 1], set))
		end--;
	return (kd_substring(src, start, end));
}
