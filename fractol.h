/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:40:34 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/19 20:39:19 by opelser       ########   odam.nl         */
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
	long		max_iterations;
	float		scale_x[2];
	float		scale_y[2];
} t_data;

int			checkjulia(float x, float y, int max_iter);
float		checkmandelbrot(float x, float y, float max_iter);
void		mandelbrot(t_data *data);


#endif