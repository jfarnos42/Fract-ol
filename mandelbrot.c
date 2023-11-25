/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 03:17:55 by jfarnos-          #+#    #+#             */
/*   Updated: 2023/11/25 04:00:49 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double creal, double cimag)
{
	int i;
	double real;
	double imag;
	double real2;
	double imag2;

	real = creal;
	imag = cimag;
	while (i <= MAX_ITER)
	{
		real2 = real * real;
		imag2 = imag * imag;
		if (real + imag > 4.0)
			return (i);
		imag = 2 * real * imag + cimag;
		real = real2 - imag2 + creal;
		i++;
	}
	return (MAX_ITER);
}

void	render_mandelbrot(t_fractal	*fractal)
{
	int	x;
	int	y;
	int	color;
	int	brightness;
	double creal;
	double cimag;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			creal = (x - WIDTH / 2.0) / (WIDTH / 4.0);
			cimag = (y - HEIGHT / 2.0) / (HEIGHT / 4.0);
			color = mandelbrot(creal, cimag);
			brightness = 255 - color * 255 / MAX_ITER;
			mlx_pixel_put(fractal->mlx, fractal->win, x, y, color);
			y++;
		}
		x++;
	}
}
