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
#define RED "\e[0;31m"
#define RESET "\e[0m"

void	captain_hook(mlx_key_data_t keydata, t_data *data)
{
	(void) keydata;
	if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
		zoom(data, 0.95);
	if (mlx_is_key_down(data->mlx, MLX_KEY_TAB))
		zoom(data, 1.05);
	if (mlx_is_key_down(data->mlx, MLX_KEY_EQUAL))
	{
		data->iter += 25;
		make_fractal(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS))
	{
		data->iter -= 25;
		make_fractal(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_R))
		init(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		move_x(data, 0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		move_x(data, -0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		move_y(data, -0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		move_y(data, 0.02);
	if (mlx_is_key_down(data->mlx, MLX_KEY_1))
	{
		data->frac = 1;
		make_fractal(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_2))
	{
		data->frac = 2;
		make_fractal(data);
	}
}

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
	mlx_terminate(data->mlx);
	return (0);
}
