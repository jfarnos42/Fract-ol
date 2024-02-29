/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:45:13 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/02/28 20:42:00 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double real, double imag)
{
	double	z_real;
	double	z_imag;
	double	tmp;
	int		i;

	z_real = 0.0;
	z_imag = 0.0;
	i = 0;
	while (i < MAX_ITER && z_real * z_real + z_imag * z_imag < 4.0)
	{
		tmp = z_real * z_real - z_imag * z_imag + real;
		z_imag = 2.0 * z_real * z_imag + imag;
		z_real = tmp;
		i++;
	}
	return (i % 256);
}

void	draw_mandelbrot(t_window *window)
{
	int		x;
	int		y;
	double	real;
	double	imag;
	int		color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = (x - WIDTH / 2.0) / window->fractal->zoom
				+ window->fractal->x;
			imag = (y - HEIGHT / 2.0) / window->fractal->zoom
				+ window->fractal->y;
			color = mandelbrot(real, imag);
			put_pixel(window, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->img_ptr,
		0, 0);
}
