/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:22:14 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/06 19:20:28 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_colour(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	color_gradient(int i)
{
	double	red;
	double	green;
	double	percentage;
	int		half;

	green = 0;
	half = 0.5 * MAX_ITERATIONS;
	percentage = (double)i / MAX_ITERATIONS;
	if (percentage < 0.5)
		red = (double)i / ((double)MAX_ITERATIONS * 0.5) * 200 + 55;
	else
	{
		red = 255;
		green = ((double)i - half) / (double)MAX_ITERATIONS * 200 + 55;
	}
	return (get_colour((int)red, (int)green, 0, 255));
}

void	set_background(mlx_image_t *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x != WIDTH)
	{
		while (y != HEIGHT)
		{
			mlx_put_pixel(img, x, y, get_colour(0, 0, 0, 255));
			y++;
		}
		y = 0;
		x++;
	}
}

t_var	*set_variables(void)
{
	t_var			*var;
	mlx_t			*mlx;
	mlx_image_t		*img;

	mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		exit(EXIT_FAILURE);
	var = malloc(sizeof(t_var));
	if (!var)
		exit(EXIT_FAILURE);
	var->nav_x = 1;
	var->nav_y = 1;
	var->zoom = 1;
	var->img = img;
	var->mlx = mlx;
	return (var);
}
