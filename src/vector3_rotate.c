#include "minirt.h"

double    vector3_scalar(t_vector3 a, t_vector3 b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector3    vector3_qrotate(t_vector3 a, double theta, t_vector3 axis)
{
    t_vector3        b;
    t_quaternion    q;

    theta = M_PI / 180 * theta;
    q = new_quaternion(theta, axis);
    b.x = a.x * (1 - 2 * (pow(q.j, 2) + pow(q.k, 2))) + a.y * (2 * (q.i * q.j
                - q.k * q.w)) + a.z * (2 * (q.i * q.k + q.j * q.w));
    b.y = a.x * (2 * (q.i * q.j + q.k * q.w)) + a.y * (1 - 2 * (pow(q.i, 2)
                + pow(q.k, 2))) + a.z * (2 * (q.j * q.k - q.i * q.w));
    b.z = a.x * (2 * (q.i * q.k - q.j * q.w)) + a.y * (2 * (q.j * q.k + q.i
                * q.w)) + a.z * (1 - 2 * (pow(q.i, 2) + pow(q.j, 2)));
    return (b);
}

t_vector3    vector3_rotate_yx(t_vector3 a, t_vector2 rotate)
{
    t_vector3    b;

    rotate.v = M_PI / 180 * -rotate.v;
    b.x = a.x;
    b.y = a.y * cos(rotate.v) - a.z * sin(rotate.v);
    b.z = a.y * sin(rotate.v) + a.z * cos(rotate.v);
    rotate.u = M_PI / 180 * -rotate.u;
    a.x = b.x * cos(rotate.u) - b.z * sin(rotate.u);
    a.y = b.y;
    a.z = b.x * sin(rotate.u) + b.z * cos(rotate.u);
    return (a);
}

t_vector3    vector3_rotate_xy(t_vector3 b, t_vector2 rotate)
{
    t_vector3    a;

    rotate.u = M_PI / 180 * -rotate.u;
    a.x = b.x * cos(rotate.u) - b.z * sin(rotate.u);
    a.y = b.y;
    a.z = b.x * sin(rotate.u) + b.z * cos(rotate.u);
    rotate.v = M_PI / 180 * -rotate.v;
    b.x = a.x;
    b.y = a.y * cos(rotate.v) - a.z * sin(rotate.v);
    b.z = a.y * sin(rotate.v) + a.z * cos(rotate.v);
    return (b);
}

t_vector2    vector3_arotate(t_vector3 a, t_vector3 b)
{
    t_vector2    c;
    t_vector2    r;

    c.u = 0;
    c.v = 0;
    r.v = -90;
    while (r.v <= 90)
    {
        r.u = 0;
        while (r.u < 360)
        {
            if (vector3_scalar(a, vector3_rotate_yx(b, r)) > vector3_scalar(a,
                    vector3_rotate_yx(b, c)))
                c = r;
            r.u++;
        }
        r.v++;
    }
    return (c);
}