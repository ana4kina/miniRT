#include "minirt.h"

static void	intersect_plane2(t_plane *plane, t_ray *ray, t_bool bump,
	t_scene *scene)
{
	ray->coordinates = matrix3_addition(ray->position, vector3_multiply(
				ray->orient, ray->t));
	ray->color = plane->color;
	texture_plane(plane, ray, bump, scene);
}

//https://www.scratchapixel.com/lessons/3d-basic-rendering/
//minimal-ray-tracer-rendering-simple-shapes/ray-plane-and-ray-disk-intersection
void	intersect_plane(t_plane *plane, t_ray *ray, t_bool bump, t_scene *scene)
{
	double		denom;
	double		t;

	denom = vector3_scalar(plane->orient, ray->orient);
	if (denom > EPSILON)
	{
		t = vector3_scalar(matrix3_subtract(plane->position, ray->position),
				plane->orient) / denom;
		if (t < EPSILON || (t + EPSILON > ray->t))
			return ;
		ray->normal = vector3_negate(plane->orient);
	}
	else if (denom < -EPSILON)
	{
		denom = vector3_scalar(vector3_negate(plane->orient), ray->orient);
		t = vector3_scalar(matrix3_subtract(plane->position, ray->position),
				vector3_negate(plane->orient)) / denom;
		if (t < EPSILON || (t + EPSILON > ray->t))
			return ;
		ray->normal = plane->orient;
	}
	else
		return ;
	ray->t = t;
	intersect_plane2(plane, ray, bump, scene);
}

void	add_plane(t_scene *scene, char *str)
{
	t_plane		*plane;
	t_vector3	position;
	t_vector3	orient;
	t_color		color;
	int			err;

	err = 0;
	position = new_vector_atof(&str, &err);
	orient = new_vector_atof(&str, &err);
	check_direction_limits(orient, &err);
	color = new_color_atoc(&str, &err);
	check_endline(&str, &err);
	if (err)
		ft_error(8);
	plane = new_plane(position, orient, color);
	plane->next = scene->planes;
	scene->planes = plane;
}

t_plane	*new_plane(t_vector3 position, t_vector3 orient, t_color color)
{
	t_plane	*plane;

	plane = kd_calloc(1, sizeof(t_plane));
	if (plane == NULL)
		ft_error(-1);
	plane->position = position;
	plane->orient = vector3_normalise(orient);
	plane->color = color;
	return (plane);
}

static char    *texture_plane_get_addr(t_img *img, t_vector2 tile)
{
    return (img->addr + ((int)fmod(fmod(tile.v, img->height) + img->height,
                img->height) * img->bytes_per_line + (int)fmod(fmod(tile.u,
                    img->width) + img->width, img->width) * (img->bits_per_pixel
                / 8)));
}

void    texture_plane(t_plane *plane, t_ray *ray, t_bool bump, t_scene *scene)
{
    t_pl        pl;

    if (!bump)
        return ;
    pl.local = matrix3_subtract(ray->coordinates, plane->position);
    pl.ulocal = vector3_normalise(pl.local);
    pl.costheta = vector3_scalar(pl.ulocal, vector3_cw(plane->orient));
    pl.tile.u = sqrt(vector3_sumpow2(pl.local)) * pl.costheta * 100;
    pl.costheta = vector3_scalar(pl.ulocal, vector3_ccw(plane->orient));
    pl.tile.v = sqrt(vector3_sumpow2(pl.local)) * pl.costheta * 100;
    pl.dst = texture_plane_get_addr(scene->texturemap, pl.tile);
    ray->color = new_color((*(unsigned int *)pl.dst & 0x00ff0000) >> 16,
            (*(unsigned int *)pl.dst & 0x0000ff00) >> 8,
            (*(unsigned int *)pl.dst & 0x000000ff));
    pl.dst = texture_plane_get_addr(scene->bumpmap, pl.tile);
    pl.color = new_vector3((*(unsigned int *)pl.dst & 0x00ff0000) >> 16,
            (*(unsigned int *)pl.dst & 0x0000ff00) >> 8,
            (*(unsigned int *)pl.dst & 0x000000ff));
    pl.color.x = (pl.color.x / 255 - 0.5) * 2;
    pl.color.y = (pl.color.y / 255 - 0.5) * 2;
    pl.color.z = (pl.color.z / 255 - 0.5) * 2;
    ray->normal = vector3_qrotate(vector3_qrotate(ray->normal, pl.color.y
                * 90, vector3_cw(plane->orient)), pl.color.x * -90,
            vector3_ccw(plane->orient));
}
