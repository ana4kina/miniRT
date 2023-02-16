#include "libkd.h"

static short	kd_strnstr_check(char const *haystack, char const *needle)
{
	while (*needle)
		if (*haystack++ != *needle++)
			return (0);
	return (1);
}	

char	*kd_strnstr(char const *haystack, char const *needle, size_t len)
{
	unsigned int	haystack_len;
	unsigned int	needle_len;

	haystack_len = kd_strnlen(haystack, len);
	needle_len = kd_strnlen(needle, len + 1);
	if (!needle_len)
		return ((char *)haystack);
	while (haystack_len-- >= needle_len && needle_len <= len--)
		if (kd_strnstr_check(haystack++, needle))
			return ((char *)--haystack);
	return (0);
}
