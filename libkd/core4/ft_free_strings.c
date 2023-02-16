#include "libkd.h"

void	*kd_free_strings(char **strings)
{
	char	**s;

	s = strings;
	while (*s)
	{
		*s = kd_free(*s);
		s++;
	}
	*s = kd_free(*s);
	strings = kd_free(strings);
	return (strings);
}
