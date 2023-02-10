/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:16:52 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/10 16:12:16 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll_func(double x, double y, void *param)
{
	t_var	*var;

	var = param;
	if (y > 0)
	{
		var->zoom *= 0.8;
		select_pixel(var);
	}
	else if (y < 0)
	{
		var->zoom *= 1.2;
		select_pixel(var);
	}
}

void	key_hook(void *param)
{
	t_var	*var;

	var = param;
	if (mlx_is_key_down(var->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(var->mlx);
	if (mlx_is_key_down(var->mlx, MLX_KEY_W))
		var->nav_y -= 0.2 * var->zoom;
	if (mlx_is_key_down(var->mlx, MLX_KEY_A))
		var->nav_x -= 0.2 * var->zoom;
	if (mlx_is_key_down(var->mlx, MLX_KEY_S))
		var->nav_y += 0.2 * var->zoom;
	if (mlx_is_key_down(var->mlx, MLX_KEY_D))
		var->nav_x += 0.2 * var->zoom;
	select_pixel(var);
}
