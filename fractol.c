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
	
// }

int	main(void)
{
	mlx_t*			mlx = mlx_init(WIDTH, HEIGHT, "banaan", true);

	mlx_image_t*	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (-1);
	mlx_image_to_window(mlx, img, 0, 0);

	// Fills in mandelbrot / julia:
	mandelbrot(img);

	// Key hook function
	// mlx_key_hook(mlx, &captain_hook, NULL);

	// Checker pixel:
	mlx_put_pixel(img, WIDTH / 2, HEIGHT / 2, 0xFF00FFFF);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

