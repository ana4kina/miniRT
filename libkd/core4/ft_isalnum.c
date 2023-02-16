#include "libkd.h"

int	kd_isalnum(int c)
{
	return (kd_isdigit(c) || kd_isalpha(c));
}
