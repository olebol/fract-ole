/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 20:44:05 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/19 21:56:27 by opelser       ########   odam.nl         */
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
	data->x[0] *= scale;
	data->x[1] *= scale;
	data->y[0] *= scale;
	data->y[1] *= scale;
	callmandelbrot(data);
}

void	init(t_data *data)
{
	data->iter = MAX_ITER;
	data->x[0] = -3;
	data->x[1] = 2;
	data->y[0] = -1.5;
	data->y[1] = 1.5;
	callmandelbrot(data);
}