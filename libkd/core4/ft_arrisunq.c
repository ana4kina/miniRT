#include "libkd.h"

int	kd_arrisunq(int *array, int count)
{
	int	i;
	int	*sorted;

	sorted = kd_arrbbl(kd_arrdup(array, count), count);
	i = 0;
	while (i < count - 1)
	{
		if (sorted[i] == sorted[i + 1])
		{
			sorted = kd_free(sorted);
			return (0);
		}
		i++;
	}
	sorted = kd_free(sorted);
	return (1);
}
