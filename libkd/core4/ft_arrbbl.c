#include "libkd.h"

int	*kd_arrbbl(int *array, int count)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (array);
}
