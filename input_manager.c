/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:27:08 by jfarnos-          #+#    #+#             */
/*   Updated: 2023/11/30 16:44:20 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook_terminate(int keycode, t_fractal *fractal)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(0);
	}
	return (0);
}

int	close_hook(void *param)
{
	mlx_destroy_window(((t_fractal *)param)->mlx, ((t_fractal *)param)->win);
	exit(0);
	return (0);
}
