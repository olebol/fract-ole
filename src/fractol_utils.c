/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 20:44:05 by opelser       #+#    #+#                 */
/*   Updated: 2023/02/22 23:38:48 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(double xdelta, double ydelta, t_data *data)
{
	float	scale;

	(void) xdelta;
	if (ydelta > 0)
		scale = 0.95;
	else
		scale = 1.05;
	data->x[0] *= scale;
	data->x[1] *= scale;
	data->y[0] *= scale;
	data->y[1] *= scale;
	make_fractal(data);
}

int	make_fractal(t_data *data)
{
	if (data->frac == 1)
		mandelbrot(data);
	else if (data->frac == 2)
		julia(data);
	mlx_key_hook(data->mlx, (mlx_keyfunc) captain_hook, data);
	mlx_scroll_hook(data->mlx, (mlx_scrollfunc) zoom, data);
	return (0);
}

void	init(t_data *data)
{
	data->iter = MAX_ITER;
	data->x[0] = -3;
	data->x[1] = 2;
	data->y[0] = 1.5;
	data->y[1] = -1.5;
	data->julia[0] = 0.150;
	data->julia[1] = 0.635;
	data->colour[0] = 2;
	data->colour[1] = 4;
	data->colour[2] = 6;
	data->mouse[0] = 0;
	data->mouse[1] = 0;
	make_fractal(data);
}

void	move_x(t_data *data, float amount)
{
	data->x[0] += amount;
	data->x[1] += amount;
	make_fractal(data);
}

void	move_y(t_data *data, float amount)
{
	data->y[0] += amount;
	data->y[1] += amount;
	make_fractal(data);
}
