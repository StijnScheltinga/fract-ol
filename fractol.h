/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:18:11 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/10 14:06:08 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <complex.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"
# define WIDTH 400
# define HEIGHT 400
# define MAX_ITERATIONS 100

typedef struct s_var {
	double		zoom;
	double		nav_x;
	double		nav_y;
	double		julia_x;
	double		julia_y;
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		*set;
}	t_var;

uint32_t	get_colour(int r, int g, int b, int a);
uint32_t	color_gradient(int i);
int			display_set(char **argv, int argc);
void		key_hook(void *param);
void		select_pixel(t_var *var);
void		mandelbrot(int x, int y, t_var *var);
void		julia(int x, int y, t_var *var);
void		set_background(mlx_image_t *img);
t_var		*set_variables(void);
char		*select_set(char **argv, int argc, t_var *var);
void		scroll_func(double x, double y, void *param);
double		ft_atof(char *str);
void		check_input(int argc, char **argv);
void		check_param(char **argv);

#endif