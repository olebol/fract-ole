/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:40:34 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/16 17:44:01 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1920
# define HEIGHT 1080
# define MAX_ITER 64

# include "MLX42/include/MLX42/MLX42.h"
# include <stddef.h>

int			checkjulia(double x, double y);
double		checkmandelbrot(double x, double y);
void		mandelbrot(mlx_image_t *img);


#endif