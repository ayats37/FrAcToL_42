/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:31:44 by taya              #+#    #+#             */
/*   Updated: 2025/02/24 23:59:21 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void    calculate_iterations(int *iteration, int max_iterations, t_complex *z, t_complex c)
{
    double tmp_real;
    while (*iteration < max_iterations && (z->real * z->real + z->imag * z->imag <= 4))
            {
                tmp_real = z->real * z->real - z->imag * z->imag + c.real;
                z->imag = 2 * z->real * z->imag + c.imag;
                z->real = tmp_real;
                (*iteration)++;
            }
}
