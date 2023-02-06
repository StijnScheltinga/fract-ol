/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:39:51 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/06 19:22:22 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_input(int argc, char **argv)
{
	if (argc <= 1 || (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) != 0)
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 5) != 0))
	{
		write (1, "please select the mandelbrot set or julia set", 46);
		exit (EXIT_FAILURE);
	}
	if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
	{
		if (ft_atoi(argv[2]) > 2 || ft_atoi(argv[2]) < -2
			|| ft_atoi(argv[3]) > 2 || ft_atoi(argv[3]) < -2)
		{
			write (1, "input should be between -2 and 2\n", 33);
			exit (EXIT_FAILURE);
		}
	}
}

char	*select_set(char **argv, int argc, t_var *var)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		return ("mandelbrot");
	else if ((ft_strncmp(argv[1], "julia", 5) == 0) && argc == 4)
	{
		var->julia_x = ft_atof(argv[2]);
		var->julia_y = ft_atof(argv[3]);
		return ("julia");
	}
	write (1, "incorrect input\n", 16);
	exit (EXIT_FAILURE);
}

double	ft_atof(char *str)
{
	double	ret;
	int		i;
	int		neg;

	ret = 0.0;
	i = 0;
	neg = 1;
	if (*str++ == '-')
		neg = -1;
	while (ft_isdigit(*str) == 1 && *str)
		ret = (ret * 10 + (*str++ - '0'));
	if (*str == '.')
		str++;
	while (ft_isdigit(*str) == 1 && *str)
	{
		ret = (ret * 10 + (*str++ - '0'));
		i++;
	}
	while (i-- != 0)
		ret = ret / 10;
	printf("%f\n", ret);
	return (ret *= neg);
}
