/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:54:46 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/16 15:11:40 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	leaks(void)
{
	system("leaks fractol");
}

int	display_set(char **argv, int argc)
{
	t_var	*var;

	var = set_variables();
	ft_memset(var->img->pixels, (char)255, WIDTH * HEIGHT * sizeof(int));
	mlx_image_to_window(var->mlx, var->img, 0, 0);
	var->set = select_set(argv, argc, var);
	mlx_scroll_hook(var->mlx, &scroll_func, var);
	mlx_loop_hook(var->mlx, &key_hook, var);
	mlx_loop(var->mlx);
	mlx_terminate(var->mlx);
	exit (EXIT_SUCCESS);
}

int	main(int argc, char	**argv)
{
	atexit(leaks);
	if (check_input(argc, argv) == 0)
		return (0);
	return (display_set(argv, argc));
}
