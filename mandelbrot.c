/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:37:30 by sschelti          #+#    #+#             */
/*   Updated: 2023/01/27 18:16:05 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(mlx_t *mlx, mlx_image_t *img, int width, int height)
{
	int				x;
	int				y;
	double			cy;
	double			cx;
	double complex	z;
	double complex	c;

	x = 0;
	y = 0;
	z = 0;
	while (x != width)
	{
		cx = x * 4 / width - 2;
		while (y != height)
		{
			cy = y * 4 / height - 2;
			c = cx + cy * I;
			z = z * z + c;
			y++;
		}
		x++;
	}
}
