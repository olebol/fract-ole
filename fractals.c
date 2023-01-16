/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractals.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:40:20 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/16 19:06:34 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		checkjulia(double x, double y)
{
	double	imaginary_x = x;
	double	imaginary_y = y;
	double	tmp;
	int		iterations = 0;
	double	cx = 0.275, cy = 0.01;

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
			iter = checkmandelbrot(scaled_x, scaled_y);
			// iter = checkjulia(scaled_x, scaled_y);
			colour = (255 * iter / MAX_ITER);
			mlx_put_pixel(img, x, y, colour);
			y++;
		}
		x++;
		y = 0;
	}
}