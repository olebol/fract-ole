/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/21 15:32:55 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/01 22:13:35 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move_hook(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		move_x(data, -0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		move_x(data, 0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		move_y(data, -0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		move_y(data, 0.02);
}

static void	fractol_hook(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_1))
	{
		data->frac = MANDELBROT;
		make_fractal(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_2))
	{
		data->frac = JULIA;
		make_fractal(data);
	}
}

static void	functionality_hook(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_R))
		init(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_EQUAL))
	{
		data->iter += 25;
		make_fractal(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS))
	{
		if (data->iter >= 25)
			data->iter -= 25;
		make_fractal(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_C))
	{
		data->colour[0] += 5;
		data->colour[1] += 7;
		data->colour[2] += 2;
		make_fractal(data);
	}
}

void	captain_hook(mlx_key_data_t keydata, t_data *data)
{
	(void) keydata;
	fractol_hook(data);
	move_hook(data);
	functionality_hook(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_P))
	{
		mlx_get_mouse_pos(data->mlx, &data->mouse[X], &data->mouse[Y]);
		data->julia[Y] = data->x[LEFT]
			+ ((float) data->mouse[X] / (float) WIDTH)
			* (data->x[RIGHT] - data->x[LEFT]);
		data->julia[Y] = data->y[UP]
			+ (float) data->mouse[Y] / (float) HEIGHT
			* (data->y[DOWN] - data->y[UP]);
		make_fractal(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}
