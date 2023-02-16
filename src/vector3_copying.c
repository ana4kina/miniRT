#include "minirt.h"

t_vector2	new_vector2(double u, double v)
{
	t_vector2	a;

	a.u = u;
	a.v = v;
	return (a);
}

t_vector3	vector3_negate(t_vector3 a)
{
	a.x = -a.x;
	a.y = -a.y;
	a.z = -a.z;
	return (a);
}

t_vector3	vector3_cw(t_vector3 a)
{
	double	tmp;

	tmp = a.x;
	a.x = a.y;
	a.y = a.z;
	a.z = tmp;
	return (a);
}

t_vector3	vector3_ccw(t_vector3 a)
{
	double	tmp;

	tmp = a.z;
	a.z = a.y;
	a.y = a.x;
	a.x = tmp;
	return (a);
}

t_vector3    new_vector3(double x, double y, double z)
{
    t_vector3    a;

    a.x = x;
    a.y = y;
    a.z = z;
    return (a);
}