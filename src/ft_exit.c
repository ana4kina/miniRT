#include "minirt.h"

void	ft_exit(int status)
{
	kd_free_all();
	exit(status);
}
