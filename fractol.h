/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:40:34 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/17 22:41:58 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// # define WIDTH 1920
// # define HEIGHT 1080
# define WIDTH 1080
# define HEIGHT 720
# define MAX_ITER 400

# include "MLX42/include/MLX42/MLX42.h"
# include <stddef.h>

typedef struct t_data {
	mlx_t		*mlx;
	mlx_image_t	*img;
	long		max_iterations;
	float		scale_x[2];
	float		scale_y[2];
} data_t;

int			checkjulia(double x, double y);
double		checkmandelbrot(double x, double y);
void		mandelbrot(data_t *data);


#endif