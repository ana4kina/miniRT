#include "libkd.h"

int	*kd_arrdup(int *array, int count)
{
	int	i;
	int	*new;

	new = kd_malloc(sizeof(int) * count);
	if (!new)
		return (new);
	i = 0;
	while (i < count)
	{
		new[i] = array[i];
		i++;
	}
	return (new);
}
