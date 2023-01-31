/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:37:30 by sschelti          #+#    #+#             */
/*   Updated: 2023/01/31 12:38:42 by sschelti         ###   ########.fr       */
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
	while (i != MAX_ITERATIONS && cabs(z) < 2)
	{
		z = (z * z) + c;
		if (cabs(z) > 2)
			mlx_put_pixel(img, x, y, colour_sort(i));
		i++;
	}
}

void	mandelbrot(mlx_image_t *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	set_background(img);
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
