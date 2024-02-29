/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:43:18 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/02/28 20:45:32 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_window *window)
{
	if (window->fractal->fractal_type == MANDELBROT)
		draw_mandelbrot(window);
	else if (window->fractal->fractal_type == JULIA)
		draw_julia(window);
	else
		exit(0);
}

void	init_fractal(t_window *window, char *fractal_name, int argc,
		char **argv)
{
	window->fractal->x = 0.0;
	window->fractal->y = 0.0;
	window->fractal->zoom = 250.0;
	if (ft_strcmp(fractal_name, "mandelbrot") == 0)
		window->fractal->fractal_type = MANDELBROT;
	else if (ft_strcmp(fractal_name, "julia") == 0)
	{
		if (argc == 4)
		{
			window->fractal->x = ft_atof(argv[2]);
			window->fractal->y = ft_atof(argv[3]);
		}
		else
		{
			window->fractal->x = 0.0;
			window->fractal->y = 0.0;
		}
		window->fractal->fractal_type = JULIA;
	}
	else
	{
		ft_printf("Invalid Fractal Name\n");
		exit(0);
	}
}

void	put_pixel(t_window *window, int x, int y, int color)
{
	int	i;

	i = (x * (window->bpp / 8)) + (y * window->size_line);
	window->img_data[i] = (unsigned char)((color * 7) % 256);
	if (window->bpp > 8)
	{
		window->img_data[i + 1] = (unsigned char)((color * 5) % 256);
		if (window->bpp > 16)
		{
			window->img_data[i + 2] = (unsigned char)((color * 3) % 256);
		}
	}
}

int	main(int argc, char **argv)
{
	t_window	window;

	window.fractal = calloc(sizeof(t_fractal), 1);
	if (!window.fractal)
		return (0);
	if (argc < 2)
	{
		ft_printf("Not enought arguments.\n");
		ft_printf("Please use ./fractol mandelbrot/julia\n");
		return (0);
	}
	init_window(&window, argv[1]);
	init_fractal(&window, argv[1], argc, argv);
	draw_fractal(&window);
	register_hooks(&window);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, window.img_ptr, 0,
		0);
	mlx_loop(window.mlx_ptr);
	free(window.fractal);
	return (0);
}
