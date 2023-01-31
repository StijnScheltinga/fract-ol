/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:22:14 by sschelti          #+#    #+#             */
/*   Updated: 2023/01/31 12:36:27 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_colour(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	colour_sort(int i)
{
	int	red;

	red = i * 2 + 55;
	return (get_colour(red, 0, 0, 255));
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
