/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:03:21 by jfarnos-          #+#    #+#             */
/*   Updated: 2023/11/30 16:54:20 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <math.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1600
# define HEIGHT 1600
# define MAX_ITER 1000

typedef struct s_fractal
{
	double	freal;
	double	fimag;
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		max_iter;
	int		endian;
}			t_fractal;

int			calc_mandelbrot(t_fractal *fractal, double creal, double cimag);
int			key_hook_terminate(int keycode, t_fractal *fractal);
int			close_hook(void *param);
void		draw_mandelbrot(t_fractal *fractal);
void 		put_pixel_to_image(int x, int y, int color, t_fractal *fractal);

#endif