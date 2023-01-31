/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:54:46 by sschelti          #+#    #+#             */
/*   Updated: 2023/01/31 15:59:40 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hook(void *param)
{
	t_var	*var;

	var = param;
	if (mlx_is_key_down(var->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(var->mlx);
		exit(EXIT_SUCCESS);
	}
	if (mlx_is_key_down(var->mlx, MLX_KEY_W))
		var->nav_y -= 0.2 * var->zoom;
	if (mlx_is_key_down(var->mlx, MLX_KEY_A))
		var->nav_x -= 0.2 * var->zoom;
	if (mlx_is_key_down(var->mlx, MLX_KEY_S))
		var->nav_y += 0.2 * var->zoom;
	if (mlx_is_key_down(var->mlx, MLX_KEY_D))
		var->nav_x += 0.2 * var->zoom;
	mandelbrot(var);
}

int	make_window(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_var			*var;

	var = malloc(sizeof(t_var));
	var->nav_x = 1;
	var->nav_y = 1;
	var->zoom = 1;
	mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		exit(EXIT_FAILURE);
	ft_memset(img->pixels, (char)255, WIDTH * HEIGHT * sizeof(int));
	var->img = img;
	var->mlx = mlx;
	mandelbrot(var);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_scroll_hook(mlx, &scroll_func, var);
	mlx_loop_hook(mlx, &hook, var);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}

int	main(void)
{
	return (make_window());
}
