#include "minirt.h"

static void	iterate_pixels(t_scene *scene)
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
				&& y % scene->everynframe == 0)		// проверка необходимого качества
			{
				if (!ray->t)
				{
					ray->t = INFINITY;
					raytrace(x, y, ray, scene);		//поиск места пересечения луча с фигурой
					compute_light(ray, scene);		//блики
				}
			}
			x++;
		}
		y++;
	}
}

int	render_next_frame(t_scene *scene) // проверка качества картинки и её улучшение/ухудшение
{
	animate(scene);
	if (scene->idle > 0)
	{
		scene->idle--;
		return (0);
	}
	else if (scene->idle < 0)
		return (0);
	if (!scene->rays_set)
		reset_rays(scene);						// создание набора лучей
	iterate_pixels(scene);						// прход по каждому пикселю для проверки на что-то
	iterate_pixels_gamma_correction(scene);		// вывод пикселей
	update_window(scene);
	scene->idle = 1;
	if (scene->everynframe >= 20)
		scene->everynframe /= 2;
	else if (scene->everynframe > 10)
		scene->everynframe = 10;
	else if (scene->everynframe > scene->maxquality)
		scene->everynframe--;
	else
		scene->idle = -1;
	return (0);
}
