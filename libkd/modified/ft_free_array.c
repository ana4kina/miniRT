#include "libkd.h"

void	*kd_free_array(void **array, int size)
{
	while (size-- > 0)
		array[size] = kd_free(array[size]);
	array = kd_free(array);
	return (NULL);
}
