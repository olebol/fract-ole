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

// int captain_hook(mlx_key_data_t data, void *param)
// {
// 	int		iter;
// 	const mlx_t *mlx = param;

// 	iter = MAX_ITER;
	
// 	if (mlx_is_key_down(mlx, MLX_KEY_Z))
// 	{
// 		iter += 10;

// 	}
// }

int	main(void)
{
	mlx_t*			mlx = mlx_init(WIDTH, HEIGHT, "banaan", true);

	mlx_image_t*	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (-1);
	if (mlx_image_to_window(mlx, img, 0, 0) == -1)
		return (-1);

	// Fills in mandelbrot / julia:
	mandelbrot(img);

	// Key hook function
	// mlx_key_hook(mlx, &captain_hook, mlx);

	// Checker pixel:
	mlx_put_pixel(img, WIDTH / 2, HEIGHT / 2, 0xFF00FFFF);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

