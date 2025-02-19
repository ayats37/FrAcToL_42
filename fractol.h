/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:58:17 by taya              #+#    #+#             */
/*   Updated: 2025/02/19 18:19:52 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
    int     width;
    int     height;
}   t_data;

typedef struct 
{
    double     real;
    double     imag;
    
}   t_complex;

typedef struct
{
    int max_iterations;
    double zoom;
    t_complex ofsset;
    t_complex   julia;    
}t_fractal;

void   put_pixel_to_image(t_data *data, int x, int y, int color);
int    create_window_img(t_data *data);
int     close_window(t_data *data);
void    draw_mandelbrot_fractal(t_data *data, t_fractal *fractal);




#endif