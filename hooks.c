/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:58:07 by taya              #+#    #+#             */
/*   Updated: 2025/02/20 18:50:14 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_hook(int keycode, t_data *data)
{
    if (keycode == 53)
        close_window(data);
    else if (keycode == 123)
        data->fractal->ofsset.real -= 20 / data->fractal->zoom;
    else if (keycode == 124)
        data->fractal->ofsset.real += 20 / data->fractal->zoom;
    else if (keycode == 125)
        data->fractal->ofsset.imag -= 20 / data->fractal->zoom;
    else if (keycode == 126)
        data->fractal->ofsset.imag += 20 / data->fractal->zoom;
    draw_mandelbrot_fractal(data, data->fractal);
    return (0);
}
int mouse_hook(int button, int x, int y, t_data *data)
{
    (void)x;
    (void)y;

    if (button == 4)
    {
        // data->fractal->ofsset.real += (x - data->width / 2) / data->fractal->zoom; 
        // data->fractal->ofsset.imag += (y - data->height / 2) / data->fractal->zoom;
        data->fractal->zoom *= 1.1;
    }
    else if (button == 5)
    {
        data->fractal->zoom /= 1.1;
        // data->fractal->ofsset.real -= (x - data->width / 2) / data->fractal->zoom; 
        // data->fractal->ofsset.imag -= (y - data->height / 2) / data->fractal->zoom;
    }
    draw_mandelbrot_fractal(data, data->fractal);
    return (0);
}