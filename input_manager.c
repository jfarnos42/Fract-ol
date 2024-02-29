/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:43:20 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/02/28 23:40:45 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	input_handler(int keycode, t_window *window, void *param)
{
	if (keycode == 53)
		kill_window(param);
	if (keycode == 123)
		window->fractal->x += 0.025;
	else if (keycode == 124)
		window->fractal->x -= 0.025;
	else if (keycode == 125)
		window->fractal->y -= 0.025;
	else if (keycode == 126)
		window->fractal->y += 0.025;
	if (keycode == 69 || keycode == 24)
		window->fractal->zoom *= 1.025;
	else if (keycode == 78 || keycode == 27)
		window->fractal->zoom /= 1.025;
	mlx_clear_window(window->mlx_ptr, window->win_ptr);
	draw_fractal(window);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->img_ptr,
		0, 0);
	return (0);
}

int	handle_mouse_input(int keycode, int x, int y, t_window *window)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		window->fractal->zoom *= 1.025;
	else if (keycode == 5)
		window->fractal->zoom /= 1.025;
	else
		return (0);
	mlx_clear_window(window->mlx_ptr, window->win_ptr);
	draw_fractal(window);
	mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, window->img_ptr,
		0, 0);
	return (0);
}
