/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:07:09 by opelser           #+#    #+#             */
/*   Updated: 2024/03/21 16:21:22 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "errors.h"
#include "libft.h"

static void		init_mlx(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!data->mlx)
		error(E_MLX_INIT);

	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
		error(E_IMAGE_INIT);

	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
		exit(EXIT_FAILURE);
}

static void		init_mandelbrot(t_data *data)
{
	data->iter = 50;
	data->x[0] = -3;
	data->x[1] = 2;
	data->y[0] = 1.5;
	data->y[1] = -1.5;

	data->colour[R] = 2;
	data->colour[G] = 4;
	data->colour[B] = 6;
}

static void		init_julia(t_data *data, int argc, char **argv)
{
	if (data->frac == JULIA && argc == 4)
	{
		data->julia[0] = ft_atof(argv[2]);
		data->julia[1] = ft_atof(argv[3]);
	}
	else
	{
		data->julia[0] = 0;
		data->julia[1] = 0.8;
	}
}

void	init(t_data *data, int argc, char **argv)
{
	init_mlx(data);

	if (ft_err_atoi(argv[1], (int *) &data->frac) == -1)
		error(E_FRACTAL);

	init_mandelbrot(data);
	init_julia(data, argc, argv);
}
