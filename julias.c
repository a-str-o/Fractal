/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julias.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 01:15:23 by yoelguer          #+#    #+#             */
/*   Updated: 2020/02/29 01:16:17 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_fr *fractol)
{
	fractol->zoom.x = 0.285;
	fractol->zoom.y = 0.01;
	fractol->max.x = 2;
	fractol->min.x = -2;
	fractol->max.y = 2;
	fractol->min.y = -2;
	fractol->itr = 250;
	fractol->id_set = 0;
	fractol->bpp = 1;
}

void	julia1(t_fr *fractol)
{
	fractol->zoom.x = 0.3;
	fractol->zoom.y = 0.5;
	fractol->max.x = 2;
	fractol->min.x = -2;
	fractol->max.y = 2;
	fractol->min.y = -2;
	fractol->itr = 250;
	fractol->id_set = 0;
	fractol->bpp = 1;
}

void	julia2(t_fr *fractol)
{
	fractol->zoom.x = -0.038088;
	fractol->zoom.y = 0.9754633;
	fractol->max.x = 2;
	fractol->min.x = -2;
	fractol->max.y = 2;
	fractol->min.y = -2;
	fractol->itr = 250;
	fractol->id_set = 0;
	fractol->bpp = 1;
}

void	julia3(t_fr *fractol)
{
	fractol->zoom.x = -0.4;
	fractol->zoom.y = 0.6;
	fractol->max.x = 2;
	fractol->min.x = -2;
	fractol->max.y = 2;
	fractol->min.y = -2;
	fractol->itr = 250;
	fractol->id_set = 0;
	fractol->bpp = 1;
}
