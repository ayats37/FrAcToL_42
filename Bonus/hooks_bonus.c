/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:23:25 by taya              #+#    #+#             */
/*   Updated: 2025/02/25 00:27:14 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int key_hook(int keycode, t_data *data)
{
    if (keycode == 53)
        close_window(data);
    else if (keycode == 123)
        data->fractal->ofsset.real -= 30 / data->fractal->zoom;
    else if (keycode == 124)
        data->fractal->ofsset.real += 30 / data->fractal->zoom;
    else if (keycode == 125)
        data->fractal->ofsset.imag -= 30 / data->fractal->zoom;
    else if (keycode == 126)
        data->fractal->ofsset.imag += 30 / data->fractal->zoom;
    if (data->fractal_type == 0)
        mandelbrot(data, data->fractal);
    else if (data->fractal_type == 1)
        julia(data, data->fractal);
    else if (data->fractal_type == 2)
        tricorn(data, data->fractal);
    else
        return (1);
    return (0);
}
int mouse_hook(int button, int x, int y, t_data *data)
{
    
    if (button == 4)
    {
        data->fractal->ofsset.real += (x - data->width / 2) / data->fractal->zoom;
        data->fractal->ofsset.imag += (y - data->height / 2) / data->fractal->zoom;
        data->fractal->zoom *= 1.1;
    }
    else if (button == 5)
    {
        data->fractal->ofsset.real += (x - data->width / 2) / data->fractal->zoom;
        data->fractal->ofsset.imag += (y - data->height / 2) / data->fractal->zoom;
        data->fractal->zoom /= 1.1;
    }
    if (data->fractal_type == 0)
        mandelbrot(data, data->fractal);
    else if (data->fractal_type == 1)
        julia(data, data->fractal);
    else if (data->fractal_type == 2)
        tricorn(data, data->fractal);
    else
        return (1);
    return (0);
}
