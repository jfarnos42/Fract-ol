/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:40:04 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/02/27 03:16:25 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

# include "./includes/Libft/libft.h"
# include "./includes/ft_printf/ft_printf.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
}					t_fractal_type;

typedef struct s_fractal
{
	double			x;
	double			y;
	double			zoom;
	t_fractal_type	fractal_type;
}					t_fractal;

typedef struct s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				bpp;
	int				size_line;
	int				endian;
	t_fractal		*fractal;
}					t_window;

void				init_window(t_window *window, char *win_name);
void				register_hooks(t_window *window);
void				init_mandelbrot(t_window *window, t_fractal *fractal);
void				put_pixel(t_window *window, int x, int y, int color);
void				draw_fractal(t_window *window);
void				draw_mandelbrot(t_window *window);
void				draw_julia(t_window *window);
void				init_julia(t_window *window, t_fractal *fractal, int argc,
						char **argv);
int					julia(double real, double imag, double julia_x,
						double julia_y);
int					kill_window(void *param);
int					handle_escape_key(int keycode, void *param);
int					mandelbrot(double real, double imag);
int					input_handler(int keycode, t_window *window, void *param);
int					handle_mouse_input(int keycode, int x, int y,
						t_window *window);

#endif