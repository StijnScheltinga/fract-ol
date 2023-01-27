/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:54:46 by sschelti          #+#    #+#             */
/*   Updated: 2023/01/27 17:47:04 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	make_window(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	uint32_t	colour;

	mlx = mlx_init(800, 800, "fractol", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, 800, 800);
	if (!img)
		exit(EXIT_FAILURE);
	colour = get_colour(0, 0, 255, 255);
	ft_memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
	mlx_image_to_window(mlx, img, 128, 128);
	mandelbrot(mlx, img, 800, 800);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
}

int	main(void)
{
	make_window();
}
