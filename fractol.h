/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:18:11 by sschelti          #+#    #+#             */
/*   Updated: 2023/01/31 12:50:13 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <complex.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"
# define WIDTH 1500
# define HEIGHT 1500
# define MAX_ITERATIONS 100

typedef struct fract
{
	uint32_t	width;
	uint32_t	height;
	mlx_t		*mlx;
}	t_fract;

uint32_t	get_colour(int r, int g, int b, int a);
uint32_t	colour_sort(int i);
int			make_window(void);
void		hook(void *param);
void		mandelbrot(mlx_image_t *img);
void		calculate_absolute(mlx_image_t *img, int x, int y);
void		set_background(mlx_image_t *img);

#endif