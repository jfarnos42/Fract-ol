/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:01:51 by jfarnos-          #+#    #+#             */
/*   Updated: 2023/11/30 17:10:59 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT,
			"Mandelbrot Set");
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->data = mlx_get_data_addr(fractal->img, &fractal->endian,
			&fractal->endian, &fractal->endian);
	fractal->max_iter = MAX_ITER;
}

void put_pixel_to_image(int x, int y, int color, t_fractal *fractal)
{
    int pixel = (x * 4) + (y * WIDTH * 4);
    
    fractal->data[pixel] = color % 255;                // blue
    fractal->data[pixel + 1] = (color * 7) % 255;       // green
    fractal->data[pixel + 2] = (color * 13) % 255;      // red
}

int	main(void)
{
	t_fractal	fractal;

	fractal_init(&fractal);
	draw_mandelbrot(&fractal);
	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.img, 0, 0);
	mlx_key_hook(fractal.win, key_hook_terminate, &fractal);
	mlx_hook(fractal.win, 17, 1L << 17, close_hook, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
