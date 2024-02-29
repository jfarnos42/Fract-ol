/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 02:12:22 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/02/28 20:46:01 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double real, double imag, double julia_x, double julia_y)
{
	double	z_real;
	double	z_imag;
	double	tmp;
	int		i;

	z_real = real;
	z_imag = imag;
	i = 0;
	while (i < MAX_ITER && z_real * z_real + z_imag * z_imag < 4.0)
	{
		tmp = z_real * z_real - z_imag * z_imag + julia_x;
		z_imag = 2.0 * z_real * z_imag + julia_y;
		z_real = tmp;
		i++;
	}
	return (i % 256);
}

void	draw_julia(t_window *window)
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
			color = julia(real, imag, window->fractal->x, window->fractal->y);
			put_pixel(window, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->img_ptr,
		0, 0);
}
