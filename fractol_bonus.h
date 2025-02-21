/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:57:27 by taya              #+#    #+#             */
/*   Updated: 2025/02/21 02:20:39 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_BONUS_H
#define FRACTOL_BONUS_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_complex
{
    double     real;
    double     imag;
    
}   t_complex;

typedef struct s_fractal
{
    int max_iterations;
    double zoom;
    t_complex ofsset;
    t_complex   julia;    
}t_fractal;

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
    t_fractal   *fractal;
    int     fractal_type;
}   t_data;





void   put_pixel_to_image(t_data *data, int x, int y, int color);
int    create_window_img(t_data *data);
int     close_window(t_data *data);
int get_color(int iteration, int max_iterations);
int key_hook(int keycode, t_data *data);
int mouse_hook(int button, int x, int y, t_data *data);
int	ft_strcmp(const char *s1, const char *s2);
double ft_atof(const char *str);
void    draw_tricorn_fractal(t_data *data, t_fractal *fractal);
void    draw_mandelbrot_fractal(t_data *data, t_fractal *fractal);
void    draw_julia_fractal(t_data *data, t_fractal *fractal);


#endif