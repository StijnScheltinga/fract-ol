/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:18:11 by sschelti          #+#    #+#             */
/*   Updated: 2023/01/31 18:11:52 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <complex.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"
# define WIDTH 512
# define HEIGHT 512
# define MAX_ITERATIONS 400

typedef struct s_var {
	double		zoom;
	double		nav_x;
	double		nav_y;
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_var;

uint32_t	get_colour(int r, int g, int b, int a);
uint32_t	colour_sort(int i);
int			make_window(void);
void		hook(void *param);
void		mandelbrot(t_var *var);
void		calculate_absolute(int x, int y, t_var *var);
void		set_background(mlx_image_t *img);
void		scroll_func(double x, double y, void *param);

#endif