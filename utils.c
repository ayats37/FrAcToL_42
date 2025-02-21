/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:57:53 by taya              #+#    #+#             */
/*   Updated: 2025/02/21 02:21:20 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fractol.h"
#include "fractol_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

double ft_atof(const char *str)
{
    int i = 0;
    double result = 0.0;
    double sign = 1.0;
    double fraction = 0.1;
    int point = 0;

    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1.0;
        i++;
    }
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (point)
            {
                result += (str[i] - '0') * fraction;
                fraction /= 10.0;
            }
            else
                result = result * 10.0 + (str[i] - '0');
        }
        else if (str[i] == '.')
            point = 1;
        else
            break;
        i++;
    }

    return (sign * result);
}
