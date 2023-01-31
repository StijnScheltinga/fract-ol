/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:16:52 by sschelti          #+#    #+#             */
/*   Updated: 2023/01/31 15:37:11 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll_func(double x, double y, void *param)
{
	t_var	*var;

	var = param;
	if (y > 0)
	{
		var->zoom *= 0.9;
		mandelbrot(var);
	}
	else if (y < 0)
	{
		var->zoom *= 1.1;
		mandelbrot(var);
	}
}
