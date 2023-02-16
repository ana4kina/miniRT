#include "libkd.h"

int	kd_tolower(int c)
{
	if (kd_isupper(c))
		return (c + 32);
	return (c);
}
