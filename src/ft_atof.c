/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: opelser <opelser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 22:39:28 by opelser       #+#    #+#                 */
/*   Updated: 2023/02/27 23:01:46 by opelser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.' || str[i] == ',')
		result += decimals(str, i +1);
	return (result * sign);
}