/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 22:10:43 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/11 23:54:21 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(data_t *data)
{
	data->scale_x[0] *= 0.9;
	data->scale_x[1] *= 0.9;
	data->scale_y[0] *= 0.9;
	data->scale_y[1] *= 0.9;
}

void	scaled(data_t *data)
{
	data->scale_x[0] = -3;
	data->scale_x[1] = 2;
	data->scale_y[0] = -1.5;
	data->scale_y[1] = 1.5;
}

#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	data_t		*data = malloc(sizeof(data_t));

	// Initializes data
	data->mlx = mlx_init(WIDTH, HEIGHT, "banaan", true);
	if (!data->mlx)
		return (-1);

	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (-1);

	data->max_iterations = MAX_ITER;

	scaled(data);
	zoom(data);

	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
		return (-1);

	// Fills in mandelbrot / julia:
	mandelbrot(data);


	// Key hook function
	// mlx_key_hook(mlx, &captain_hook, mlx);

	// Checker pixel:
	mlx_put_pixel(data->img, WIDTH / 2, HEIGHT / 2, 0xFF00FFFF);

	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (0);
}

