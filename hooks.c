/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:58:07 by taya              #+#    #+#             */
/*   Updated: 2025/02/20 21:16:38 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
        draw_mandelbrot_fractal(data, data->fractal);
    else
        draw_julia_fractal(data, data->fractal);
    return (0);
}
int mouse_hook(int button, int x, int y, t_data *data)
{
    (void)x;
    (void)y;

    if (button == 4)
        data->fractal->zoom *= 1.1;
    else if (button == 5)
        data->fractal->zoom /= 1.1;
    if (data->fractal_type == 0)
        draw_mandelbrot_fractal(data, data->fractal);
    else
        draw_julia_fractal(data, data->fractal);
    return (0);
}