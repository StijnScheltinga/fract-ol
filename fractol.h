/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:18:11 by sschelti          #+#    #+#             */
/*   Updated: 2023/01/30 16:58:09 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <complex.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"
# define WIDTH 1024
# define HEIGHT 1024
# define MAX_ITERATIONS 150

typedef struct fract
{
	uint32_t	width;
	uint32_t	height;
	mlx_t		*mlx;
}	t_fract;

uint32_t	get_colour(int r, int g, int b, int a);
int			make_window(void);
void		hook(void *param);
void		mandelbrot(mlx_image_t *img);
void		calculate_absolute(mlx_image_t *img, int x, int y);
void		set_background(mlx_image_t *img);

#endif