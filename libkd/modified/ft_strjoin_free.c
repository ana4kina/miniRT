#include "libkd.h"

char	*kd_strjoin_free(char *s1, char *s2, int option)
{
	char	*str;

	str = kd_strjoin(s1, s2);
	if (option == 0 || option == 1)
		kd_free(s1);
	if (option == 0 || option == 2)
		kd_free(s2);
	return (str);
}
