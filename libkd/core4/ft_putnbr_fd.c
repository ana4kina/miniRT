#include "libkd.h"

int	kd_putnbr_fd(int n, int fd)
{
	char			nbr[12];
	unsigned short	i;

	i = 0;
	while (n > 9 || n < -9)
	{
		nbr[i++] = kd_abs(n % 10) + '0';
		n /= 10;
	}
	nbr[i++] = kd_abs(n) + '0';
	if (n < 0)
		nbr[i++] = '-';
	nbr[i] = 0;
	return (kd_putstr_fd(kd_strrev(nbr), fd));
}
