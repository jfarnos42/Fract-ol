/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 03:17:55 by jfarnos-          #+#    #+#             */
/*   Updated: 2023/11/30 16:57:20 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_mandelbrot(t_fractal *fractal, double creal, double cimag)
{
	int		iter;
	double	real;
	double	imag;
	double	real_temp;

	iter = 0;
	real = 0;
	imag = 0;
	while (iter < fractal->max_iter)
	{
		real_temp = real;
		real = real * real - imag * imag + creal;
		imag = 2 * real_temp * imag + cimag;
		if ((real * real + imag * imag) > 4)
			return (iter);
		iter++;
	}
	return (iter);
}

void	draw_mandelbrot(t_fractal *fractal)
{
	double	creal;
	double	cimag;
	int		color;
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			creal = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			cimag = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
			color = calc_mandelbrot(fractal, creal, cimag);
			put_pixel_to_image(x, y, color, fractal);
			x++;
		}
		y++;
	}
}
