/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:03:21 by jfarnos-          #+#    #+#             */
/*   Updated: 2023/11/25 04:01:28 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"

#define WIDTH 1280
#define HEIGHT 720
#define MAX_ITER 1000

typedef struct s_fractal
{
	double creal;
	double cimag;
	int max_iter;
	void *mlx;
	void *win;
	void *img;
	char *data;
	int bpp;
	int size_line;
	int endian;
} t_fractal;

int		mandelbrot(double creal, double cimag);
void	render_mandelbrot(t_fractal	*fractal);

#endif