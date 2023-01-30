/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:37:30 by sschelti          #+#    #+#             */
/*   Updated: 2023/01/30 16:59:36 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_absolute(mlx_image_t *img, int x, int y)
{
	double			cx;
	double			cy;
	double complex	c;
	double complex	z;
	int				i;

	cx = x * ((double)4 / WIDTH) - 2;
	cy = y * ((double)4 / HEIGHT) - 2;
	c = cx + cy * I;
	z = 0 + 0 * I;
	i = 0;
	while (i != MAX_ITERATIONS)
	{
		z = (z * z) + c;
		i++;
	}
	if (cabs(z) < 2)
		mlx_put_pixel(img, x, y, get_colour(255, 0, 0, 255));
	else
		mlx_put_pixel(img, x, y, get_colour(0, 0, 0, 0));
}

void	mandelbrot(mlx_image_t *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x != WIDTH)
	{
		while (y != HEIGHT)
		{
			calculate_absolute(img, x, y);
			y++;
		}
		y = 0;
		x++;
	}
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
