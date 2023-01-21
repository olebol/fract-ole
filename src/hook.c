/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/21 15:32:55 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/21 15:32:55 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	captain_hook(mlx_key_data_t keydata, t_data *data)
{
	(void) keydata;
	if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
		zoom(data, 0.95);
	if (mlx_is_key_down(data->mlx, MLX_KEY_TAB))
		zoom(data, 1.05);
	if (mlx_is_key_down(data->mlx, MLX_KEY_EQUAL))
	{
		data->iter += 25;
		make_fractal(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS))
	{
		data->iter -= 25;
		make_fractal(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_R))
		init(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		move_x(data, 0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		move_x(data, -0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		move_y(data, -0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		move_y(data, 0.02);
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
