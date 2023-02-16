#include "libkd.h"

int	kd_arrissrt(int *array, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
