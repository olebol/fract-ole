/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 22:10:43 by opelser       #+#    #+#                 */
/*   Updated: 2023/01/11 19:51:59 by opelser       ########   odam.nl         */
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

int	main(void)
{
	mlx_t*			mlx = mlx_init(WIDTH, HEIGHT, "banaan", true);

	mlx_image_t*	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);

	ft_memset(img->pixels, 100, img->width * img->height * 4);
	mlx_put_pixel(img, 500, 500, 0xFF00FFFF);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}