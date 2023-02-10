/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:39:51 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/10 14:45:36 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_input(int argc, char **argv)
{
	if (argc > 4)
	{
		write (1, "To many arguments, select mandelbrot or julia\n", 47);
		write (1, "Julia set should have two parameters between -2 and 2\n", 55);
		exit (EXIT_FAILURE);
	}
	if (argc == 1 || (argc == 2 && (ft_strncmp(argv[1], "mandelbrot", 10) != 0))
		|| argc == 3 || (argc == 4 && (ft_strncmp(argv[1], "julia", 5)) != 0))
	{
		write (1, "please select the mandelbrot set or julia set\n", 46);
		write (1, "Julia set should have two parameters between -2 and 2\n", 55);
		exit (EXIT_FAILURE);
	}
	if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
	{
		check_param(argv);
		if (ft_atoi(argv[2]) > 2 || ft_atoi(argv[2]) < -2
			|| ft_atoi(argv[3]) > 2 || ft_atoi(argv[3]) < -2)
		{
			write (1, "parameters should be between -2.0 and 2.0\n", 43);
			exit (EXIT_FAILURE);
		}
	}
}

void	check_param(char **argv)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	while (i != 4)
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0 && (argv[i][j] != '.'
				&& argv[i][j] != '-'))
			{
				write (1, "parameters should be between -2.0 and 2.0\n", 43);
				exit (EXIT_FAILURE);
			}
			j++;
		}
		j = 0;
		i++;
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
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
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
	return (ret *= neg);
}
