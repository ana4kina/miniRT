#include "libkd.h"

char	*kd_substring(char const *src, unsigned int start, unsigned int end)
{
	if (end < start)
		end = start;
	return (kd_substr(src, start, end - start));
}
