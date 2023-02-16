#include "minirt.h"

// лучи из камеры, поиск места пересечения с фигурами
// в функцию приходит пустой ray, функция считает шаг в отосительных
// координатах и формирует
//step -- перевод из координат mlx в координаты сцены (из обсолютных
// координат пиксельной матрицы, а относительным координатам сцены [-1; 1])
void	raytrace(int x, int y, t_ray *ray, t_scene *scene)
{
	t_vector2	step;

	step = new_vector2((x - scene->width / (double)2) / scene->width
			* (double)2, -(y - scene->height / (double)2) / scene->width
			* (double)2);
	if (scene->view == 0)
		ray_orthographic(scene->camera, step, ray);
	if (scene->view == 1)
		ray_perspective_tan(scene->camera, step, ray);
	else if (scene->view == 2)
		ray_perspective_spherise(scene->camera, step, ray);
	else if (scene->view == 3)
		ray_perspective_spherise2(scene->camera, step, ray);
	else if (scene->view == 4)
		ray_perspective_spherise3(scene->camera, step, ray);
	else if (scene->view == 5)
		ray_perspective_quaternion(scene, x, y, ray);
	else if (scene->view == 6)
		ray_perspective_quaternion2(scene, x, y, ray);
	intersect(ray, scene);
}

// включает поворот камеры, если флаг play активирован
//printf("c u %f v %f\n", scene->camera->rotate.u, scene->camera->rotate.v);
void	animate(t_scene *scene)
{
	if (scene->play)
	{
		scene->everynframe = scene->minquality;
		scene->idle = 0;
		scene->rays_set = FALSE;
		scene->gamma = 1;
		if (scene->play == 3)
		{
			rotate_camera_xz(scene->camera, -10);
			rotate_camera_y(scene->camera, 10);
		}
		else if (scene->play == 2)
			rotate_camera_xz(scene->camera, -10);
		else if (scene->play == 1)
			rotate_camera_y(scene->camera, 10);
		else
			scene->play = 0;
	}
}

void	update_window(t_scene *scene)
{
	if (!scene->oddframe)
	{
		mlx_put_image_to_window(scene->mlx, scene->window, scene->img->img,
			0, 0);
		scene->oddframe = 1;
	}
	else
	{
		mlx_put_image_to_window(scene->mlx, scene->window, scene->img2->img,
			0, 0);
		scene->oddframe = 0;
	}
	hud(scene);
}

void	iterate_pixels_gamma_correction(t_scene *scene)
{
	t_ray	*ray;
	int		x;
	int		y;

	y = 0;
	while (y < scene->height)
	{
		x = 0;
		while (x < scene->width)
		{
			ray = &scene->rays[y * scene->width + x];
			if (x % scene->everynframe == 0
				&& y % scene->everynframe == 0)
				draw_pixel(scene, x, y, colour_gamma_apply(ray->color, scene));
			x++;
		}
		y++;
	}
}

void	reset_rays(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->width * scene->height)
		scene->rays[i++].t = 0;
	scene->rays_set = TRUE;
}

double    math_quadratic_equation(t_quad *q)
{
    q->t1 = 0;
    q->t2 = 0;
    q->d = pow(q->b, 2) - 4 * q->a * q->c;
    if (q->d < 0 && q->d > -EPSILON)
        q->d = 0;
    if (q->d < 0)
        return (-1);
    q->sqrt_d = sqrt(q->d);
    q->t1 = (-q->b - q->sqrt_d) / (2 * q->a);
    q->t2 = (-q->b + q->sqrt_d) / (2 * q->a);
    if (fmin(q->t1, q->t2) > EPSILON)
        return (fmin(q->t1, q->t2));
    return (fmax(q->t1, q->t2));
}

void    intersect_disc(t_disc *disc, t_ray *ray, t_scene *scene)
{
    t_ray    tmp_ray;
    t_plane    plane;

    plane.position = disc->position;
    plane.orient = disc->orient;
    plane.color = disc->color;
    tmp_ray = *ray;
    intersect_plane(&plane, &tmp_ray, FALSE, scene);
    if (tmp_ray.t + EPSILON > ray->t)
        return ;
    if (vector3_sumpow2(matrix3_subtract(
                tmp_ray.coordinates, disc->position)) > pow(disc->radius, 2))
        return ;
    *ray = tmp_ray;
}

void    intersect2(t_ray *ray, t_scene *scene)
{
    t_cone        *cone;
    t_cylinder    *cylinder;

    cone = scene->cones;
    while (cone)
    {
        intersect_cone(cone, ray, scene);
        cone = cone->next;
    }
    cylinder = scene->cylinders;
    while (cylinder)
    {
        intersect_cylinder(cylinder, ray, scene);
        cylinder = cylinder->next;
    }
}

void    intersect(t_ray *ray, t_scene *scene)
{
    t_plane        *plane;
    t_sphere    *sphere;

    plane = scene->planes;
    while (plane)
    {
        intersect_plane(plane, ray, scene->bump, scene);
        plane = plane->next;
    }
    sphere = scene->spheres;
    while (sphere)
    {
        intersect_sphere(sphere, ray, scene);
        sphere = sphere->next;
    }
    intersect2(ray, scene);
}
