/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractals.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:40:20 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/16 22:13:11 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		checkjulia(double x, double y)
{
	double	imaginary_x = x;
	double	imaginary_y = y;
	double	tmp;
	int		iterations = 0;
	double	cx = 0.150, cy = 0.635;

	while ((imaginary_x * imaginary_x + imaginary_y * imaginary_y) <= 4 && iterations < MAX_ITER)
	{
		tmp = (imaginary_x * imaginary_x) - (imaginary_y * imaginary_y) + cx;
		imaginary_y = 2 * (imaginary_x * imaginary_y) + cy;
		imaginary_x = tmp;
		iterations++;
	}
	return (iterations);
}

double		checkmandelbrot(double x, double y)
{
	double	imaginary_x = x;
	double	imaginary_y = y;
	double	tmp;
	double	iterations = 0;

	while ((imaginary_x * imaginary_x + imaginary_y * imaginary_y) <= 4 && iterations < MAX_ITER)
	{
		tmp = (imaginary_x * imaginary_x) - (imaginary_y * imaginary_y) + x;
		imaginary_y = 2 * (imaginary_x * imaginary_y) + y;
		imaginary_x = tmp;
		iterations++;
	}
	return (iterations);
}

uint32_t get_rgba(int r, int g, int b, int a)
{
	return((r << 24) + (g << 16) + (b << 8) + a);
}

void	mandelbrot(mlx_image_t *img)
{
	double		x = 0, y = 0;
	double		scaled_x, scaled_y;
	double		iter;
	double		colour;

	while (x < img->width)
	{
		scaled_x = -3 + (x / WIDTH) * (2 - -3);
		while (y < img->height)
		{
			scaled_y = -1.5 + (y / HEIGHT) * (1.5 - -1.5);
			// iter = checkmandelbrot(scaled_x, scaled_y);
			iter = checkjulia(scaled_x, scaled_y);
			if (iter == MAX_ITER)
				colour = 0xFF;
			else
				colour = get_rgba(0xFF, 0xFF, 0x00, (255 * iter / MAX_ITER) * 2);
			mlx_put_pixel(img, x, y, colour);
			y++;
		}
		x++;
		y = 0;
	}
}