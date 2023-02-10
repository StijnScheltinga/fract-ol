/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschelti <sschelti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:16:59 by sschelti          #+#    #+#             */
/*   Updated: 2023/02/10 16:10:55 by sschelti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_multiply(t_complex num1, t_complex num2)
{
	t_complex	result;

	result.real = num1.real * num2.real - num1.imaginary * num2.imaginary;
	result.imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;
	return (result);
}

t_complex	complex_add(t_complex num1, t_complex num2)
{
	t_complex	result;

	result.real = num1.real + num2.real;
	result.imaginary = num1.imaginary + num2.imaginary;
	return (result);
}

double	complex_absolute(t_complex num1)
{
	double	result;

	result = sqrt(num1.real * num1.real + num1.imaginary * num1.imaginary);
	return (result);
}
