/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:39:51 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/16 15:15:57 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_input(int argc, char **argv)
{
	if (argc > 4 || argc == 1)
	{
		read_txt();
		return (0);
	}
	else if ((argc == 2 && (ft_strncmp(argv[1], "mandelbrot", 11) != 0))
		|| (argc >= 3 && (ft_strncmp(argv[1], "julia", 6)) != 0))
	{
		read_txt();
		return (0);
	}
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		check_param(argv);
		if (ft_atoi(argv[2]) > 2 || ft_atoi(argv[2]) < -2
			|| ft_atoi(argv[3]) > 2 || ft_atoi(argv[3]) < -2)
		{
			read_txt();
			return (0);
		}
	}
	return (1);
}

void	read_txt(void)
{
	int		fd;
	char	buff[295];

	fd = open("wrong_input.txt", O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	if (read(fd, buff, 295) < 0)
		exit(EXIT_FAILURE);
	write(1, &buff, 295);
	close(fd);
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
				read_txt();
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
		printf("%f\n%f\n", var->julia_x, var->julia_y);
		return ("julia");
	}
	read_txt();
	exit (EXIT_FAILURE);
}
