#include "minirt.h"

t_color	colour_amplify(t_color colour, double amplifier)
{
	colour.r *= amplifier;
	colour.g *= amplifier;
	colour.b *= amplifier;
	return (colour);
}

t_color	colour_add(t_color colour, t_color colour_add)
{
	colour.r += colour_add.r;
	colour.g += colour_add.g;
	colour.b += colour_add.b;
	return (colour);
}

t_color	colour_matrix_amplify(t_color colour, t_color colour_amplifier)
{
	int	mix;

	mix = 10;
	colour.r = colour.r * colour_amplifier.r / 255
		+ colour_amplifier.g / mix + colour_amplifier.b / mix;
	colour.g = colour.g * colour_amplifier.g / 255
		+ colour_amplifier.r / mix + colour_amplifier.b / mix;
	colour.b = colour.b * colour_amplifier.b / 255
		+ colour_amplifier.r / mix + colour_amplifier.g / mix;
	return (colour);
}

t_color	colour_gamma_collect(t_color colour, t_scene *scene)
{
	scene->gamma = fmax(scene->gamma,
			kd_max(kd_max(colour.r, colour.g), colour.b) / (double)255);
	return (colour);
}

t_color	colour_gamma_apply(t_color colour, t_scene *scene)
{
	if (scene->gamma_correction)
	{
		colour.r /= scene->gamma;
		colour.g /= scene->gamma;
		colour.b /= scene->gamma;
		return (colour);
	}
	else
		return (colour_clamp(colour));
}
