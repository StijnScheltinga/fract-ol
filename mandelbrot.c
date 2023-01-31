/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:37:30 by sschelti          #+#    #+#             */
/*   Updated: 2023/01/31 15:51:37 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_absolute(int x, int y, t_var *var)
{
	double			cx;
	double			cy;
	double complex	c;
	double complex	z;
	int				i;

	cx = var->nav_x + x * ((double)4 * var->zoom / WIDTH) - (2 * var->zoom);
	cy = var->nav_y + y * ((double)4 * var->zoom / HEIGHT) - (2 * var->zoom);
	c = cx + cy * I;
	z = 0 + 0 * I;
	i = 0;
	while (i != MAX_ITERATIONS && cabs(z) < 2)
	{
		z = (z * z) + c;
		if (cabs(z) > 2)
			mlx_put_pixel(var->img, x, y, colour_sort(i));
		i++;
	}
}

void	mandelbrot(t_var *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	set_background(var->img);
	while (x != WIDTH)
	{
		while (y != HEIGHT)
		{
			calculate_absolute(x, y, var);
			y++;
		}
		y = 0;
		x++;
	}
}
