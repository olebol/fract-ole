/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractals.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 17:40:20 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/01 20:17:38 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	get_rgba(t_data *d, float iter)
{
	const int	r = (d->colour[R] * iter);
	const int	g = (d->colour[G] * iter);
	const int	b = (d->colour[B] * iter);
	const int	a = 255;

	return ((r << 24) | (g << 16) | (b << 8) | a);
}

static float	checkmandelbrot(int max_iter, float orig_x, float orig_y)
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

static int	checkjulia(t_data *d, float x, float y)
{
	float	tmp;
	int		iter;

	iter = 0;
	while ((x * x + y * y) <= 4 && iter < d->iter)
	{
		tmp = (x * x) - (y * y) + d->julia[X];
		y = 2 * (x * y) + d->julia[Y];
		x = tmp;
		iter++;
	}
	return (iter);
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
		scaled[X] = d->x[LEFT] + (x / WIDTH) * (d->x[RIGHT] - d->x[LEFT]);
		while (y < HEIGHT)
		{
			scaled[Y] = d->y[UP] + (y / HEIGHT) * (d->y[DOWN] - d->y[UP]);
			iter = checkmandelbrot(d->iter, scaled[X], scaled[Y]);
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
		scaled[X] = d->x[LEFT] + (x / WIDTH) * (d->x[RIGHT] - d->x[LEFT]);
		while (y < HEIGHT)
		{
			scaled[Y] = d->y[UP] + (y / HEIGHT) * (d->y[DOWN] - d->y[UP]);
			iter = checkjulia(d, scaled[X], scaled[Y]);
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
