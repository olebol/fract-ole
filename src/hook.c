/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:32:55 by opelser           #+#    #+#             */
/*   Updated: 2024/03/21 16:12:23 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move_hook(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->x[0] += 0.2;
		data->x[1] += 0.2;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->x[0] -= 0.2;
		data->x[1] -= 0.2;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
	{
		data->y[0] += 0.2;
		data->y[1] += 0.2;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
	{
		data->y[0] -= 0.2;
		data->y[1] -= 0.2;
	}
}

static void	julia_mouse_hook(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
	{
		mlx_get_mouse_pos(data->mlx, &data->mouse[X], &data->mouse[Y]);
		data->julia[X] = data->x[LEFT]
			+ ((float) data->mouse[X] / (float) WIDTH)
			* (data->x[RIGHT] - data->x[LEFT]);
		data->julia[Y] = data->y[UP]
			+ (float) data->mouse[Y] / (float) HEIGHT
			* (data->y[DOWN] - data->y[UP]);
	}
}

static void	functionality_hook(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_R))
	{
		data->x[0] = -3;
		data->x[1] = 2;
		data->y[0] = 1.5;
		data->y[1] = -1.5;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_EQUAL))
	{
		data->iter += 25;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS))
	{
		if (data->iter >= 25)
			data->iter -= 25;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_C))
	{
		data->colour[0] += 5;
		data->colour[1] += 7;
		data->colour[2] += 2;
	}
}

void	zoom(double xdelta, double ydelta, void *context)
{
	t_data	*data;
	float	scale;

	data = (t_data *) context;
	(void) xdelta;
	if (ydelta > 0)
		scale = 0.95;
	else
		scale = 1.05;
	data->x[0] *= scale;
	data->x[1] *= scale;
	data->y[0] *= scale;
	data->y[1] *= scale;
}

void	captain_hook(void *context)
{
	t_data		*data;

	data = (t_data *) context;

	move_hook(data);
	functionality_hook(data);
	julia_mouse_hook(data);

	// Change fractal
	if (mlx_is_key_down(data->mlx, MLX_KEY_1))
		data->frac = MANDELBROT;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_2))
		data->frac = JULIA;

	// Exit
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);

	// Draw fractal
	if (data->frac == MANDELBROT)
		mandelbrot(data);
	else if (data->frac == JULIA)
		julia(data);
}
