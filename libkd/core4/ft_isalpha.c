#include "libkd.h"

int	kd_isalpha(int c)
{
	return (kd_isupper(c) || kd_islower(c));
}
