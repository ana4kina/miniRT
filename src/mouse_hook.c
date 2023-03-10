#include "minirt.h"

static void	mouse_hook_button1(t_scene *scene, t_ray *ray)
{
	scene->camera->rotate_origin = scene->camera->position;
	if (scene->view)
		scene->camera->rotate = vector3_arotate(ray->orient,
				scene->camera->orient);
	else if (ray->t < INFINITY)
		scene->camera->rotate = vector3_arotate(vector3_normalise(
					matrix3_subtract(ray->coordinates,
						scene->camera->position)), scene->camera->orient);
	else
		scene->camera->rotate = vector3_arotate(vector3_normalise(
					matrix3_subtract(matrix3_addition(
							ray->position, vector3_multiply(ray->orient,
								100)), scene->camera->position)),
				scene->camera->orient);
	scene->everynframe = scene->minquality;
	scene->rays_set = FALSE;
	scene->idle = 0;
}

int	mouse_hook(int button, int x, int y, t_scene *scene)
{
	t_ray	ray;

	if (x < 0 || x >= scene->width || y < 0 || y >= scene->height)
		return (0);
	ray = scene->rays[y * scene->width + x];
	if (!ray.t)
	{
		ray.t = INFINITY;
		raytrace(x, y, &ray, scene);
	}
	if (button == 1)
		mouse_hook_button1(scene, &ray);
	if (button == 2)
	{
		if (ray.t < INFINITY)
			scene->camera->rotate_origin = ray.coordinates;
		else
			scene->camera->rotate_origin = scene->camera->position;
	}
	return (0);
}
