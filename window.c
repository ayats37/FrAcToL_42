/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:57:50 by taya              #+#    #+#             */
/*   Updated: 2025/02/19 20:02:08 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void put_pixel_to_image(t_data *data, int x, int y, int color)
{
    char *dest;
    if (x >= 0 && x < data->width && y >= 0 && y < data->height)
    {
        dest = data->addr + ((y * data->line_length) + (x * (data->bpp / 8)));
        *(unsigned int *)dest = color;
    }
}

int create_window_img(t_data *data)
{
    data->width = 800;
    data->height = 700;

    data->mlx = mlx_init();
    if (!data->mlx)
        return (0);
    data->win = mlx_new_window(data->mlx, data->width, data->height, "fract-ol");
    if (!data->win)
    {
        free(data->mlx);
        return (0);
    }
    data->img = mlx_new_image(data->mlx, data->width, data->height);
    if (!data->img)
    {
        mlx_destroy_window(data->mlx, data->win);
        free(data->mlx);   
        return(0);
    }
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length, &data->endian);
    return (1);
}

int close_window(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img);
    mlx_destroy_window(data->mlx, data->win);
    free(data->mlx);
    exit(0);
    return (0);
}

// int main()
// {
//     t_data data = {0};
//     int x;
//     int y;
//     int color;

//     if (!create_window_img(&data))
//         return (1);

//     y = 0;
//     while (y < data.height)
//     {
//         x = 0;
//         while (x < data.width)
//         {
//             color = (x * 256 / data.width) << 16 | (y * 256 / data.height) << 8 | (x * y * 256 / (data.width * data.height));
//             put_pixel_to_image(&data, x, y, color);
//             x++;
//         }
//         y++;
//     }
//     mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
//     mlx_hook(data.win, 17, 0, close_window, &data);
//     mlx_loop(data.mlx);
//     return (0);
// }