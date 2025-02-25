/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:58:07 by taya              #+#    #+#             */
/*   Updated: 2025/02/25 01:09:56 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		close_window(data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->fractal->zoom *= 1.1;
	else if (button == 5)
		data->fractal->zoom /= 1.1;
	if (data->fractal_type == 0)
		mandelbrot(data, data->fractal);
	else
		julia(data, data->fractal);
	return (0);
}
