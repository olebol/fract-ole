/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/21 15:32:55 by opelser       #+#    #+#                 */
/*   Updated: 2023/02/27 16:51:03 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_hook(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		move_x(data, 0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		move_x(data, -0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		move_y(data, -0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		move_y(data, 0.02);
}

void	fractol_hook(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_1))
	{
		data->frac = 1;
		make_fractal(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_2))
	{
		data->frac = 2;
		make_fractal(data);
	}
}

void	functionality_hook(t_data *data)
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
		mlx_get_mouse_pos(data->mlx, &data->mouse[0], &data->mouse[1]);
		data->julia[0] = data->x[0]
			+ ((float) data->mouse[0] / (float) WIDTH)
			* (data->x[1] - data->x[0]);
		data->julia[1] = data->y[0]
			+ (float) data->mouse[1] / (float) HEIGHT
			* (data->y[1] - data->y[0]);
		make_fractal(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}
