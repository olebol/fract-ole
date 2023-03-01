/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 22:07:09 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/01 22:14:56 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_data *data)
{
	data->iter = MAX_ITER;
	data->x[0] = -3;
	data->x[1] = 2;
	data->y[0] = 1.5;
	data->y[1] = -1.5;
	data->julia[0] = 0;
	data->julia[1] = 0.8;
	data->colour[R] = 2;
	data->colour[G] = 4;
	data->colour[B] = 6;
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

void	param_to_julia(t_data *data, char **argv)
{
	data->julia[0] = ft_atof(argv[2]);
	data->julia[1] = ft_atof(argv[3]);
	make_fractal(data);
}
