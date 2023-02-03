/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stijn <stijn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:54:46 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/03 17:59:09 by stijn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	display_set(char **argv)
{
	t_var	*var;

	var = set_variables();
	ft_memset(var->img->pixels, (char)255, WIDTH * HEIGHT * sizeof(int));
	mlx_image_to_window(var->mlx, var->img, 0, 0);
	select_set(argv, var);
	mlx_scroll_hook(var->mlx, &scroll_func, var);
	mlx_loop_hook(var->mlx, &key_hook, var);
	mlx_loop(var->mlx);
	exit (EXIT_SUCCESS);
}

int	main(int argc, char	**argv)
{
	if (argc == 2)
		return (display_set(argv));
	else
		return(0);
}
