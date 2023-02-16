/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:22:14 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/16 14:12:39 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_colour(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	color_gradient(int i)
{
	int	red;
	int	green;
	int	blue;

	red = 0;
	green = (i * 10) % 256;
	blue = (i * 5) % 256;
	return (get_colour(red, green, blue, 255));
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

double	ft_atof(char *str)
{
	double	ret;
	int		i;
	int		neg;

	ret = 0.0;
	i = 0;
	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (ft_isdigit(*str) == 1 && *str)
		ret = (ret * 10 + (*str++ - '0'));
	if (*str == '.')
		str++;
	while (ft_isdigit(*str) == 1 && *str)
	{
		ret = (ret * 10 + (*str++ - '0'));
		i++;
	}
	while (i-- != 0)
		ret = ret / 10;
	return (ret *= neg);
}
