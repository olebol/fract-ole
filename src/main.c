/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 22:10:43 by opelser       #+#    #+#                 */
/*   Updated: 2023/02/28 20:19:34 by opelser       ########   odam.nl         */
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
		write(1, "\t[1] Mandelbrot\n\t[2] Julia + [x] + [y]\n", 40);
		write(1, RESET, 5);
	}
	return (EXIT_FAILURE);
}
void	init(t_data *data)
{
	data->iter = MAX_ITER;
	data->x[0] = -3;
	data->x[1] = 2;
	data->y[0] = 1.5;
	data->y[1] = -1.5;
	data->julia[0] = 0;
	data->julia[1] = 0.8;
	data->colour[0] = 2;
	data->colour[1] = 4;
	data->colour[2] = 6;
	data->mouse[0] = 0;
	data->mouse[1] = 0;
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

#include <stdio.h>
int	ft_valid_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0')
		return (EXIT_FAILURE);
	if (argc == 2 && argv[1][0] == '1')
		return (EXIT_SUCCESS);
	else if (argc == 4 && argv[1][0] == '1')
		return (EXIT_FAILURE);
	while (argv[2][i])
	{
		if ((!(argv[2][i] >= '0' && argv[2][i] <= '9') && argv[2][i] != '.'))
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (argv[3][i])
	{
		if ((!(argv[3][i] >= '0' && argv[3][i] <= '9') && argv[3][i] != '.'))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if ((argc != 2 && argc != 4) || ft_valid_input(argc, argv))
		return (ft_error(0));
	data.frac = argv[1][0] - 48;
	data.mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!data.mlx)
		return (EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img)
		return (EXIT_FAILURE);
	if (mlx_image_to_window(data.mlx, data.img, 0, 0) == -1)
		return (free(data.img), mlx_terminate(data.mlx), EXIT_FAILURE);
	init(&data);
	if (argc == 4)
		param_to_julia(&data, argv);
	mlx_loop(data.mlx);
	mlx_close_window(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
