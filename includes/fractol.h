/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:40:34 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/21 15:26:56 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1080
# define HEIGHT 720
# define MAX_ITER 50

# include "MLX42/include/MLX42/MLX42.h"
# include <stddef.h>

#include <stdio.h> // !!! REMOVE !!! for printf
#include <stdlib.h> // for malloc
#include <unistd.h> // for write (only in fractol.c?)

typedef struct s_data {
	mlx_t		*mlx; // graphics library initialized
	mlx_image_t	*img; // image thats on my screen
	int			frac; // Specifies the fractal
	long		iter; // max iterations
	float		x[2]; // projected / scaled x
	float		y[2]; // projected / scaled y
	float		julia[2]; // XY location for fixed julia point
} t_data;

int			make_fractal(t_data *data);
void		captain_hook(mlx_key_data_t keydata, t_data *data);
void		zoom(t_data *data, float scale);
void		init(t_data *data);
void		move_x(t_data *data, float amount);
void		move_y(t_data *data, float amount);
void		mandelbrot(t_data *data);
void		julia(t_data *data);

#endif
