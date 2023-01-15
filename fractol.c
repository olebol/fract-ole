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

#define WIDTH 720
#define HEIGHT 480
#define MAX_ITER 1000

#include "MLX42/MLX42.h"
#include <stddef.h>

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

int		checkmandelbrot(double x, double y)
{
	double	imaginary_x = x;
	double	imaginary_y = y;
	double	tmp;
	int		iterations = 0;

	while ((imaginary_x * imaginary_x + imaginary_y * imaginary_y) <= 4 && iterations < MAX_ITER)
	{
		tmp = (imaginary_x * imaginary_x) - (imaginary_y * imaginary_y) + x;
		imaginary_y = 2 * (imaginary_x * imaginary_y) + y;
		imaginary_x = tmp;
		iterations++;
	}
	return (iterations);
}


//  julia set not working yet
int		checkjulia(double x, double y)
{
	double	imaginary_x = x;
	double	imaginary_y = y;
	double	tmp;
	int		iterations = 0;
	double	cx = 0.56, cy = -0.156;


	while ((imaginary_x * imaginary_x + imaginary_y * imaginary_y) <= 4 && iterations < MAX_ITER)
	{
		tmp = (imaginary_x * imaginary_x) - (imaginary_y * imaginary_y) + cx;
		imaginary_y = 2 * (imaginary_x * imaginary_y) + cy;
		imaginary_x = tmp;
		iterations++;
	}
	return (iterations);
}

void	mandelbrot(mlx_image_t *img)
{
	double		x = 0, y = 0;
	double		scaled_x, scaled_y;
	int			iter;

	
	while (x <= img->width)
	{
		scaled_x = -2 + (x / WIDTH) * (1 - -2);
		while (y <= img->height)
		{
			scaled_y = -1 + (y / HEIGHT) * (1 - -1);
			iter = checkmandelbrot(scaled_x, scaled_y);
			// iter = checkjulia(scaled_x, scaled_y);
			if (iter == MAX_ITER)
				mlx_put_pixel(img, x, y, 0x00000000);
			else
				mlx_put_pixel(img, x, y, 0xFFFFFFFF);
			y++;
		}
		x++;
		y = 0;
	}
}

int	main(void)
{
	mlx_t*			mlx = mlx_init(WIDTH, HEIGHT, "banaan", true);

	mlx_image_t*	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (-1);
	mlx_image_to_window(mlx, img, 0, 0);

	// Fills in mandelbrot / julia:
	mandelbrot(img);

	// Checker pixel:
	mlx_put_pixel(img, WIDTH / 2, HEIGHT / 2, 0xFF00FFFF);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}

