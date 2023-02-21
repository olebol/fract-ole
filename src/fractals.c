/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractals.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:40:20 by opelser       #+#    #+#                 */
/*   Updated: 2023/02/21 22:50:20 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	checkjulia(t_data *d, float x, float y)
{
	float	tmp;
	int		iter;

	iter = 0;
	while ((x * x + y * y) <= 4 && iter < d->iter)
	{
		tmp = (x * x) - (y * y) + d->julia[0];
		y = 2 * (x * y) + d->julia[1];
		x = tmp;
		iter++;
	}
	return (iter);
}

float	checkmandelbrot(float orig_x, float orig_y, int max_iter)
{
	float	x;
	float	y;
	float	tmp;
	float	iter;

	y = orig_y;
	x = orig_x;
	iter = 0;
	while ((x * x + y * y) <= 4 && iter < max_iter)
	{
		tmp = (x * x) - (y * y) + orig_x;
		y = 2 * (x * y) + orig_y;
		x = tmp;
		iter++;
	}
	return (iter);
}

uint32_t	get_rgba(t_data *d, float iter)
{
	uint32_t	colour;
	int			r = (d->colour[0] * iter);
	int			g = (d->colour[1] * iter);
	int			b = (d->colour[2] * iter);
	int			a = 255;

	colour = (r << 24) | (g << 16) | (b << 8) | a;
	return (colour);
}

void	mandelbrot(t_data *d)
{
	float		x;
	float		y;
	float		scaled[2];
	float		iter;
	int			colour;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		scaled[0] = d->x[0] + (x / WIDTH) * (d->x[1] - d->x[0]);
		while (y < HEIGHT)
		{
			scaled[1] = d->y[0] + (y / HEIGHT) * (d->y[1] - d->y[0]);
			iter = checkmandelbrot(scaled[0], scaled[1], d->iter);
			if (iter == d->iter)
				colour = 0xFF;
			else
				colour = get_rgba(d, iter);
			mlx_put_pixel(d->img, x, y, colour);
			y++;
		}
		x++;
		y = 0;
	}
}

void	julia(t_data *d)
{
	float		x;
	float		y;
	float		scaled[2];
	float		iter;
	int			colour;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		scaled[0] = d->x[0] + (x / WIDTH) * (d->x[1] - d->x[0]);
		while (y < HEIGHT)
		{
			scaled[1] = d->y[0] + (y / HEIGHT) * (d->y[1] - d->y[0]);
			iter = checkjulia(d, scaled[0], scaled[1]);
			if (iter == d->iter)
				colour = 0xFF;
			else
				colour = get_rgba(d, iter);
			mlx_put_pixel(d->img, x, y, colour);
			y++;
		}
		x++;
		y = 0;
	}
}
