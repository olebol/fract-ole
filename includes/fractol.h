/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:40:34 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/01 22:19:25 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1080
# define HEIGHT 720
# define MAX_ITER 50
# define RED "\e[0;31m"
# define RESET "\e[0m"

# define MANDELBROT 1
# define JULIA 2

# define LEFT 0
# define RIGHT 1
# define UP 0
# define DOWN 1

# define X 0
# define Y 1

# include "MLX42/include/MLX42/MLX42.h"
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

// # include <stdio.h> // for printf

/*
*mlx;			// graphics library initialized
*img;			// image thats on my screen
frac;			// Specifies the fractal
iter;			// max iterations
x[2];			// projected / scaled x
y[2];			// projected / scaled y
julia[2];		// XY location for fixed julia point
colour[3];		// [0][1][2] = [R][G][B]
mouse[2];		// XY of mouse[]
*/

enum colours {R, G, B};

typedef struct s_data {
	mlx_t			*mlx;
	mlx_image_t		*img;
	int				frac;
	long			iter;
	float			x[2];
	float			y[2];
	float			julia[2];
	enum colours	colour[3];
	int32_t			mouse[2];
}	t_data;

// ~ input.c
int			validate_input(int argc, char **argv);
int			ft_error(int code);
float		ft_atof(const char *str);

// ~ utils.c
void		init(t_data *data);
int			make_fractal(t_data *data);
void		param_to_julia(t_data *data, char **argv);

// ~ hook.c
void		captain_hook(mlx_key_data_t keydata, t_data *data);

// ~ hook_utils.c
void		zoom(double xdelta, double ydelta, t_data *data);
void		move_x(t_data *data, float amount);
void		move_y(t_data *data, float amount);

// ~ fractals.c
void		mandelbrot(t_data *data);
void		julia(t_data *data);


#endif
