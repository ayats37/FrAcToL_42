/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:57:59 by taya              #+#    #+#             */
/*   Updated: 2025/02/20 17:05:24 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
    t_data data;
    t_fractal fractal;

    fractal.max_iterations = 100;
    fractal.zoom = 200;
    fractal.ofsset.real = -0.5;
    fractal.ofsset.imag = 0;
    data.fractal = &fractal;
    
    if (!create_window_img(&data))
        return (1);
    draw_mandelbrot_fractal(&data, &fractal);

    mlx_key_hook(data.win, key_hook, &data);
    mlx_mouse_hook(data.win, mouse_hook, &data);
    mlx_hook(data.win, 17, 0, close_window, &data);
    mlx_loop(data.mlx);
    return (0);
}