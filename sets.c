/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:37:30 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/03 18:39:46 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(int x, int y, t_var *var)
{
	long double			cx;
	long double			cy;
	long double complex	c;
	long double complex	z;
	int					i;

	cx = var->nav_x + x * ((double)4 * var->zoom / WIDTH) - (2 * var->zoom);
	cy = var->nav_y + y * ((double)4 * var->zoom / HEIGHT) - (2 * var->zoom);
	c = cx + cy * I;
	z = 0 + 0 * I;
	i = 0;
	while (i != MAX_ITERATIONS && cabs(z) < 2)
	{
		z = (z * z) + c;
		if (cabs(z) > 2)
			mlx_put_pixel(var->img, x, y, color_gradient(i));
		i++;
	}
}

void	julia(int x, int y, t_var *var)
{
	long double			zx;
	long double			zy;
	long double complex	c;
	long double complex	z;
	int					i;

	zx = var->nav_x + x * ((double)4 * var->zoom / WIDTH) - (2 * var->zoom);
	zy = var->nav_y + y * ((double)4 * var->zoom / HEIGHT) - (2 * var->zoom);
	c = -1 + 0 * I;
	z = zx + zy * I;
	i = 0;
	while (i != MAX_ITERATIONS && cabs(z) < 2)
	{
		z = (z * z) + c;
		if (cabs(z) > 2)
			mlx_put_pixel(var->img, x, y, color_gradient(i));
		i++;
	}
}

void	select_pixel(t_var *var)
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
			if (ft_strncmp(var->set, "julia", 5) == 0)
				julia(x, y, var);
			else
				mandelbrot(x, y, var);
			y++;
		}
		y = 0;
		x++;
	}

}
