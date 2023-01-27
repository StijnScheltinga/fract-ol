/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:18:11 by sschelti          #+#    #+#             */
/*   Updated: 2023/01/27 17:25:39 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <complex.h>
# include "lib/MLX42/include/MLX42/MLX42.h"
# include "lib/libft/libft.h"

uint32_t	get_colour(int r, int g, int b, int a);
void		make_window(void);
void		hook(void *param);
void		mandelbrot(mlx_t *mlx, mlx_image_t *img, int width, int height);

#endif