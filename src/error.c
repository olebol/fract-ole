/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:43:51 by evalieve          #+#    #+#             */
/*   Updated: 2024/03/21 16:21:44 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "libft.h"

#include <unistd.h>

const char	*ft_strerror(t_error error)
{
	static const char		*messages[] =
	{
		[E_MALLOC]			= "Memory allocation failed",
		[E_ARGC]			= "Invalid number of arguments",
		[E_FRACTAL]			= "Invalid fractal, options are 1 [Mandelbrot] or 2 [Julia]",
		[E_COORDS]			= "Invalid coordinates",
		[E_MLX_INIT]		= "Failed to initialize mlx",
		[E_IMAGE_INIT]		= "Failed to initialize an image",
	};

	return (messages[error]);
}

void	error(t_error exit_code)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putendl_fd("FRACTOL: ", STDERR_FILENO);
	ft_putendl_fd((char *) ft_strerror(exit_code), STDERR_FILENO);
	ft_putstr_fd(RESET, STDERR_FILENO);

	exit(exit_code);
}
