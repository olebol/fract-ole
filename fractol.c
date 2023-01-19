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
		callmandelbrot(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_MINUS))
	{
		data->iter -= 25;
		callmandelbrot(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_R))
		init(data);
}

int	main(void)
{
	t_data		*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (-1);
	data->mlx = mlx_init(WIDTH, HEIGHT, "banaan", true);
	if (!data->mlx)
		return (-1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (-1);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
		return (-1);
	init(data);
	mlx_put_pixel(data->img, WIDTH / 2, HEIGHT / 2, 0xFF00FFFF);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (0);
}
