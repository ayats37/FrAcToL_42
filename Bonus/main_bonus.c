/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:20:02 by taya              #+#    #+#             */
/*   Updated: 2025/02/25 01:47:40 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	fractal_type(t_data *data, t_fractal *fractal, int argc, char **argv)
{
	if (argc < 2 || (ft_strcmp(argv[1], "mandelbrot") != 0 && ft_strcmp(argv[1],
				"julia") != 0 && ft_strcmp(argv[1], "tricorn") != 0))
	{
		fprintf(stderr, "Usage: ./fractol [mandelbrot | julia | tricorn]\n");
		exit(1);
	}
	if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc == 4)
		{
			fractal->julia.real = ft_atof(argv[2]);
			fractal->julia.imag = ft_atof(argv[3]);
		}
		else
		{
			fractal->julia.real = -0.8;
			fractal->julia.imag = 0.156;
		}
		data->fractal_type = 1;
	}
	else if (ft_strcmp(argv[1], "tricorn") == 0)
		data->fractal_type = 2;
	else if (ft_strcmp(argv[1], "mandelbrot") == 0)
		data->fractal_type = 0;
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_fractal	fractal;

	fractal.max_iterations = 100;
	fractal.zoom = 200;
	fractal.ofsset.real = 0;
	fractal.ofsset.imag = 0;
	data.fractal = &fractal;
	if (!create_window_img(&data))
		return (1);
	fractal_type(&data, &fractal, argc, argv);
	if (data.fractal_type == 0)
		mandelbrot(&data);
	else if (data.fractal_type == 1)
		julia(&data, &fractal);
	else if (data.fractal_type == 2)
		tricorn(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
