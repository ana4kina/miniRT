#include "minirt.h"

t_img	*new_image(char *path, int width, int height, t_scene *scene)
{
	t_img	*img;

	img = kd_calloc(1, sizeof(t_img));
	if (!img)
		ft_error(-1);
	if (path)
		img->img = mlx_xpm_file_to_image(scene->mlx, path,
				&img->width, &img->height);
	else
		img->img = mlx_new_image(scene->mlx, width, height);
	if (!img->img)
		ft_error(-1);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->bytes_per_line, &img->endian);
	if (!img->addr)
		ft_error(-1);
	return (img);
}
