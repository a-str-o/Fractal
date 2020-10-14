/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:10:51 by yoelguer          #+#    #+#             */
/*   Updated: 2020/02/29 00:27:02 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(void)
{
	ft_putendl("/**********************************************/");
	ft_putendl("/*         Usage : ./fractol <...>            */");
	ft_putendl("/**********************************************/");
	ft_putendl("/*                   --> julia.c              */");
	ft_putendl("/*                   --> mandelbrot.c         */");
	ft_putendl("/*                   --> astro.c              */");
	ft_putendl("/**********************************************/");
}

int		fractol(int id)
{
	t_fr	fr;

	fr.id_set = id;
	fr.color = 0xFFFFFF;
	fr.mlx_ptr = mlx_init();
	fr.win_ptr = mlx_new_window(fr.mlx_ptr, 500, 500, "Fractol");
	fr.img_ptr = mlx_new_image(fr.mlx_ptr, 500, 500);
	fr.mlx_addr = (int *)mlx_get_data_addr(fr.img_ptr, &fr.bpp, &fr.sl, &fr.e);
	if (id == 0)
		ft_julia(&fr);
	if (id == 1)
		ft_mandelbrot(&fr);
	if (id == 2)
		ft_astro(&fr);
	mlx_put_image_to_window(fr.img_ptr, fr.win_ptr, fr.img_ptr, 0, 0);
	mlx_hook(fr.win_ptr, KEYPRESS, SHIFTMAASK_1, keys_hook, &fr);
	mlx_hook(fr.win_ptr, BUTTONPRESS, SHIFTMAASK_0, mouse_hook, &fr);
	mlx_hook(fr.win_ptr, MOTIONNOTIFY, SHIFTMAASK_0, mouse_move, &fr);
	mlx_hook(fr.win_ptr, DESTRYNOTIFY, SHIFTMAASK_0, exit_hook, &fr);
	mlx_loop(fr.mlx_ptr);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		if (!ft_strcmp(av[1], "julia.c"))
			return (fractol(0));
		if (!ft_strcmp(av[1], "mandelbrot.c"))
			return (fractol(1));
		if (!ft_strcmp(av[1], "astro.c"))
			return (fractol(2));
	}
	ft_error();
	return (0);
}
