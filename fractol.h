/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:40:34 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/19 21:57:50 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// # define WIDTH 1920
// # define HEIGHT 1080
# define WIDTH 1080
# define HEIGHT 720
# define MAX_ITER 50

# include "MLX42/include/MLX42/MLX42.h"
# include <stddef.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct s_data {
	mlx_t		*mlx;
	mlx_image_t	*img;
	long		iter;
	float		x[2];
	float		y[2];
} t_data;

int			callmandelbrot(t_data *data);
void		captain_hook(mlx_key_data_t keydata, t_data *data);
void		zoom(t_data *data, float scale);
void		init(t_data *data);
void		mandelbrot(t_data *data);


#endif