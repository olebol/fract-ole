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

#define WIDTH 1000
#define HEIGHT 1000

#include "MLX42/MLX42.h"
#include <stddef.h>

/*
typedef struct mlx
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}	mlx_t;
*/

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

void noshitfromnoone(mlx_image_t *img, uint32_t colour, uint32_t interval)
{
	uint32_t		x;
	uint32_t		y;
	int				offset;

	x = 0;
	y = 0;
	offset = 0;
	while(x < img->width && y <= img->height)
	{
		mlx_put_pixel(img, x + offset, y, colour);
		x += interval;
		if (x + offset >= img->width)
		{
			x = 0;
			y++;
			offset++;
			if (offset >= interval)
				offset = 0;
		}
	}
}

int	main(void)
{
	mlx_t*			mlx = mlx_init(WIDTH, HEIGHT, "banaan", true);

	mlx_image_t*	img = mlx_new_image(mlx, WIDTH / 4, HEIGHT / 4);
	if (!img)
		return (-1);
	mlx_image_to_window(mlx, img, 250, 250);

	uint32_t		colour = 0xFF00FFFF;
	ft_memset(img->pixels, 255, img->width * img->height * 4);

	noshitfromnoone(img, colour, 2);
	// mlx_put_pixel(img, 10, 10, 0xFF00FFFF);
	// mlx_put_pixel(img, 25, 25, 0xFFFFF00F);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}