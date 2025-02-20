/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:57:56 by taya              #+#    #+#             */
/*   Updated: 2025/02/20 20:13:34 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    draw_mandelbrot_fractal(t_data *data, t_fractal *fractal)
{
    int py;
    int px;
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
            c.real = (px - data->width / 2) / fractal->zoom + fractal->ofsset.real;
            c.imag = (py - data->height / 2) / fractal->zoom + fractal->ofsset.imag; 
            z.real = 0;
            z.imag = 0;
            iteration = 0;
            while (iteration < fractal->max_iterations && ((z.real * z.real + z.imag * z.imag) <= 4))
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
