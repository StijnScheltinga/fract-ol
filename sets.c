/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:37:30 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/10 15:45:06 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(int x, int y, t_var *var)
{
	double		cx;
	double		cy;
	t_complex	c;
	t_complex	z;
	int			i;

	cx = var->nav_x + x * ((double)4 * var->zoom / WIDTH) - (2 * var->zoom);
	cy = var->nav_y + y * ((double)4 * var->zoom / HEIGHT) - (2 * var->zoom);
	c.real = cx;
	c.imaginary = cy;
	z.real = 0;
	z.imaginary = 0;
	i = 0;
	while (i != MAX_ITERATIONS && complex_absolute(z) < 2)
	{
		z = complex_add(complex_multiply(z, z), c);
		if (complex_absolute(z) > 2)
			mlx_put_pixel(var->img, x, y, color_gradient(i));
		i++;
	}
}

void	julia(int x, int y, t_var *var)
{
	double		zx;
	double		zy;
	t_complex	c;
	t_complex	z;
	int			i;

	zx = var->nav_x + x * ((double)4 * var->zoom / WIDTH) - (2 * var->zoom);
	zy = var->nav_y + y * ((double)4 * var->zoom / HEIGHT) - (2 * var->zoom);
	c.real = var->julia_x;
	c.imaginary = var->julia_y;
	z.real = zx;
	z.imaginary = zy;
	i = 0;
	while (i != MAX_ITERATIONS && complex_absolute(z) < 2)
	{
		z = complex_add(complex_multiply(z, z), c);
		if (complex_absolute(z) > 2)
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
			else if (ft_strncmp(var->set, "mandelbrot", 10) == 0)
				mandelbrot(x, y, var);
			y++;
		}
		y = 0;
		x++;
	}
}
