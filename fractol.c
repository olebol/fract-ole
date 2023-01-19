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
void captain_hook(mlx_key_data_t keydata, t_data *data);

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	temp = b;
	i = 0;
	while (len > i)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (b);
}


int callmandelbrot(t_data *data)
{
	// Fills in mandelbrot / julia:
	// ft_memset(data->img->pixels, 0xFF, WIDTH * HEIGHT * 4);
	mandelbrot(data);
	mlx_put_pixel(data->img, WIDTH / 2, HEIGHT / 2, 0xFF00FFFF);

	// Key hook function
	mlx_key_hook(data->mlx, (mlx_keyfunc) captain_hook, data);
	return (0);
}

void	zoom(t_data *data, float scale)
{
	data->scale_x[0] *= scale;
	data->scale_x[1] *= scale;
	data->scale_y[0] *= scale;
	data->scale_y[1] *= scale;
	callmandelbrot(data);
}

void	scaled(t_data *data)
{
	data->scale_x[0] = -3;
	data->scale_x[1] = 2;
	data->scale_y[0] = -1.5;
	data->scale_y[1] = 1.5;
}

void captain_hook(mlx_key_data_t keydata, t_data *data)
{
	(void) keydata;

	if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
		zoom(data, 0.95);
	if (mlx_is_key_down(data->mlx, MLX_KEY_TAB))
		zoom(data, 1.05);
	if (mlx_is_key_down(data->mlx, MLX_KEY_I))
	{
		data->max_iterations += 25;
		printf("%ld \n", data->max_iterations);
		callmandelbrot(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_R))
	{
		scaled(data);
		data->max_iterations = MAX_ITER;
		callmandelbrot(data);
	}
}

int	main(void)
{
	t_data		*data = malloc(sizeof(t_data));

	// Initializes data
	data->mlx = mlx_init(WIDTH, HEIGHT, "banaan", true);
	if (!data->mlx)
		return (-1);

	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		return (-1);

	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
		return (-1);

	// ft_memset(data->reset->)
	data->max_iterations = MAX_ITER;

	scaled(data);
	// zoom(data);

	callmandelbrot(data);

	// Checker pixel:
	mlx_put_pixel(data->img, WIDTH / 2, HEIGHT / 2, 0xFF00FFFF);

	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (0);
}

