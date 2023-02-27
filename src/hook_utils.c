/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 20:44:05 by opelser       #+#    #+#                 */
/*   Updated: 2023/02/27 23:06:31 by opelser       ########   odam.nl         */
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
