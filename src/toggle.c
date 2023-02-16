#include "minirt.h"

t_bool	toggle(t_bool *b)
{
	if (!*b)
		*b = TRUE;
	else
		*b = FALSE;
	return (*b);
}
