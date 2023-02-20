/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 20:44:05 by opelser       #+#    #+#                 */
/*   Updated: 2023/02/20 19:39:12 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scroll(double xdelta, double ydelta, t_data *data)
{
	(void) xdelta;
	if (ydelta > 0)
		zoom(data, 0.95);
	else if (ydelta < 0)
		zoom(data, 1.05);
}

int	make_fractal(t_data *data)
{
	if (data->frac == 1)
		mandelbrot(data);
	else if (data->frac == 2)
		julia(data);
	mlx_key_hook(data->mlx, (mlx_keyfunc) captain_hook, data);
	mlx_scroll_hook(data->mlx, (mlx_scrollfunc) scroll, data);
	return (0);
}

void	zoom(t_data *data, float scale)
{
	data->x[0] *= scale;
	data->x[1] *= scale;
	data->y[0] *= scale;
	data->y[1] *= scale;
	make_fractal(data);
}

void	init(t_data *data)
{
	data->iter = MAX_ITER;
	data->x[0] = -3;
	data->x[1] = 2;
	data->y[0] = -1.5;
	data->y[1] = 1.5;
	data->julia[0] = 0.150;
	data->julia[1] = 0.635;
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
