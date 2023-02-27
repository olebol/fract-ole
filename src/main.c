/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 22:10:43 by opelser       #+#    #+#                 */
/*   Updated: 2023/02/27 17:01:10 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_error(int code)
{
	if (code == 0)
	{
		write(1, RED, 8);
		write(1, "Incorrect arguments\n\n", 22);
		write(1, "List of available fractals:\n", 29);
		write(1, "\t[1] Mandelbrot\n\t[2] Julia\n", 28);
		write(1, RESET, 5);
		return (-1);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 2 || (argv[1][0] != '1' && argv[1][0] != '2'))
		return (ft_error(0));
	data = malloc(sizeof(t_data));
	if (!data)
		return (-1);
	data->frac = argv[1][0] - 48;
	data->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!data->mlx)
		return ((free(data), -1));
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return ((free(data), -1));
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
		return ((free(data), -1));
	init(data);
	mlx_loop(data->mlx);
	mlx_close_window(data->mlx);
	mlx_terminate(data->mlx);
	free(data);
	return (0);
}
