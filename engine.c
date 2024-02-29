/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:20:00 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/02/29 01:04:55 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_window(t_window *window, char *win_name)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, WIDTH, HEIGHT, win_name);
	window->img_ptr = mlx_new_image(window->mlx_ptr, WIDTH, HEIGHT);
	window->img_data = mlx_get_data_addr(window->img_ptr, &window->bpp,
			&window->size_line, &window->endian);
}

int	kill_window(void *param)
{
	(void)param;
	exit(0);
}

void	register_hooks(t_window *window)
{
	mlx_hook(window->win_ptr, 2, 1, input_handler, window);
	mlx_hook(window->win_ptr, 4, 0, handle_mouse_input, window);
	mlx_hook(window->win_ptr, 5, 0, handle_mouse_input, window);
	mlx_hook(window->win_ptr, 17, 0, kill_window, window);
}
