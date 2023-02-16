#include "../libkd.h"

int	kd_strcmpi(char const *s1, char const *s2)
{
	while (*s1 && kd_tolower(*s1) == kd_tolower(*s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)kd_tolower(*s1) - (unsigned char)kd_tolower(*s2));
}
