/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 20:44:05 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/19 20:48:00 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	callmandelbrot(t_data *data)
{
	mandelbrot(data);
	mlx_key_hook(data->mlx, (mlx_keyfunc) captain_hook, data);
	return (0);
}

void	zoom(t_data *data, float scale)
{
	data->scale_x[0] *= scale;
	data->scale_x[1] *= scale;
	data->scale_y[0] *= scale;
	data->scale_y[1] *= scale;
	callmandelbrot(data);
}

void	init(t_data *data)
{
	data->max_iterations = MAX_ITER;
	data->scale_x[0] = -3;
	data->scale_x[1] = 2;
	data->scale_y[0] = -1.5;
	data->scale_y[1] = 1.5;
	callmandelbrot(data);
}