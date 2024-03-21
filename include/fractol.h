/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:40:34 by opelser           #+#    #+#             */
/*   Updated: 2024/03/21 16:29:09 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1080
# define HEIGHT 720

# define LEFT 0
# define RIGHT 1
# define UP 0
# define DOWN 1

# define X 0
# define Y 1

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

// # include <stdio.h> // for printf

enum e_fractal
{
	MANDELBROT = 1,
	JULIA
};

enum e_colours
{
	R,
	G,
	B
};

/**
	* @param *mlx 			graphics library initialized
	* @param *img 			image thats on my screen
	* @param frac 			Specifies the fractal
	* @param iter 			max iterations
	* @param x[2] 			projected / scaled x
	* @param y[2] 			projected / scaled y
	* @param julia[2] 		XY location for fixed julia point
	* @param colour[3] 		[0][1][2] = [R][G][B]
	* @param mouse[2] 		XY of mouse[]
**/
typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	enum e_fractal	frac;
	long			iter;
	float			x[2];
	float			y[2];
	float			julia[2];
	int				colour[3];
	int32_t			mouse[2];
}	t_data;

// Input validation
void		validate_input(int argc, char **argv);

// Init
void		init(t_data *data, int argc, char **argv);

// MLX hooks
void		captain_hook(void *data);
void		zoom(double xdelta, double ydelta, void *data);

// Fractal drawing
void		mandelbrot(t_data *data);
void		julia(t_data *data);

#endif
