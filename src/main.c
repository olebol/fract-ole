/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:10:43 by opelser           #+#    #+#             */
/*   Updated: 2024/03/21 16:20:44 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "errors.h"

int	main(int argc, char **argv)
{
	t_data	data;

	validate_input(argc, argv);

	init(&data, argc, argv);

	mlx_loop_hook(data.mlx, &captain_hook, (void *) &data);
	mlx_scroll_hook(data.mlx, &zoom, (void *) &data);
	mlx_loop(data.mlx);

	mlx_terminate(data.mlx);

	return (0);
}
