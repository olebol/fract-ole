/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractals.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:40:20 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/17 22:36:42 by opelser       ########   odam.nl         */
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

#include <stdio.h>
void	mandelbrot(data_t *d)
{
	double		x = 0, y = 0;
	double		scaled_x, scaled_y;
	double		iter;
	double		colour;

	while (x < WIDTH)
	{
		scaled_x = d->scale_x[0] + (x / WIDTH) * (d->scale_x[1] - d->scale_x[0]);
		while (y < HEIGHT)
		{
			scaled_y = d->scale_y[0] + (y / HEIGHT) * (d->scale_y[1] - d->scale_y[0]);
			iter = checkmandelbrot(scaled_x, scaled_y);
			// iter = checkjulia(scaled_x, scaled_y);
			if (iter == MAX_ITER)
				colour = 0xFF;
			else
				colour = get_rgba(0xFF, 0xFF, 0x00, (255 * iter / MAX_ITER) * 2);
			mlx_put_pixel(d->img, x, y, colour);
			y++;
		}
		x++;
		y = 0;
	}
}