/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:58:04 by taya              #+#    #+#             */
/*   Updated: 2025/02/21 02:20:55 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fractol.h"
#include "fractol_bonus.h"

void    draw_julia_fractal(t_data *data, t_fractal *fractal)
{
    int px;
    int py;
    int iteration;
    double  tmp_real;
    t_complex c;
    t_complex z;
    int color;
    
    py = 0;
    while (py < data->height)
    {
        px = 0;
        while (px < data->width)
        {
            c.real = fractal->julia.real;
            c.imag = fractal->julia.imag;
            z.real = (px - data->width / 2) / fractal->zoom + fractal->ofsset.real;
            z.imag = (py - data->height / 2) / fractal->zoom + fractal->ofsset.imag;
            iteration = 0;
            while (iteration < fractal->max_iterations && (z.real * z.real + z.imag * z.imag <= 4))
            {
                tmp_real = z.real * z.real - z.imag * z.imag + c.real;
                z.imag = 2 * z.real * z.imag + c.imag;
                z.real = tmp_real;
                iteration++;
            }
            color = get_color(iteration, fractal->max_iterations);
            put_pixel_to_image(data, px, py, color);
            px++;
        }
        py++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

