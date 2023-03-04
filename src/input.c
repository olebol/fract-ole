/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 22:39:28 by opelser       #+#    #+#                 */
/*   Updated: 2023/03/01 22:20:24 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	validate_coords(char *str)
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
	return (EXIT_SUCCESS);
}

int	validate_input(int argc, char **argv)
{
	if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0')
		return (EXIT_FAILURE);
	if (argc == 2 && argv[1][0] == '1')
		return (EXIT_SUCCESS);
	else if (argc == 4 && argv[1][0] == '1')
		return (EXIT_FAILURE);
	if (validate_coords(argv[2]) == 1 || validate_coords(argv[3]) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_error(int code)
{
	if (code == 0)
	{
		write(1, RED, 8);
		write(1, "Incorrect arguments\n\n", 22);
		write(1, "List of available fractals:\n", 29);
		write(1, "\t[1] Mandelbrot\n\t[2] Julia + [x] + [y]\n", 40);
		write(1, RESET, 5);
	}
	return (EXIT_FAILURE);
}

static float	decimals(const char *str, int i)
{
	float	factor;
	float	result;
	
	result = 0;
	factor = 0.1;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result += (str[i] - '0') * factor;
		factor *= 0.1;
		i++;
	}
	return (result);
}

float	ft_atof(const char *str)
{
	int		sign;
	int		i;
	float	result;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		result += decimals(str, i + 1);
	return (result * sign);
}
