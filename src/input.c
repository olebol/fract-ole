/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opelser <opelser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:39:28 by opelser           #+#    #+#             */
/*   Updated: 2024/03/21 16:23:13 by opelser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/errors.h"
#include "libft.h"

static bool	validate_coords(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((!(str[i] >= '0' && str[i] <= '9')
				&& str[i] != '.' && str[0] != '-'))
			return (EXIT_FAILURE);
		i++;
	}

	if (i == 0)
		return (false);

	return (true);
}

void		validate_input(int argc, char **argv)
{
	if (argc != 2 && argc != 4)
		error(E_ARGC);

	if (ft_strlen(argv[1]) != 1)
		error(E_FRACTAL);

	if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0')
		error(E_FRACTAL);

	if (argc == 2)
	{
		if (argv[1][0] == '2')
			error(E_FRACTAL);
	}
	else
	{
		if (argv[1][0] == '1')
			error(E_FRACTAL);

		if (validate_coords(argv[2]) == 1 || validate_coords(argv[3]) == 1)
			error(E_COORDS);
	}
}
