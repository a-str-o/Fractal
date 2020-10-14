/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 00:52:28 by yoelguer          #+#    #+#             */
/*   Updated: 2020/02/29 01:08:00 by yoelguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		keys_move(int keycode, t_fr *fr)
{
	double	mov;

	if (keycode >= LEFT_ARROW && keycode <= UP_ARROW)
	{
		mov = 10 * fabs(fr->max.x - fr->min.x) / 60;
		if (keycode == DOWN_ARROW || keycode == UP_ARROW)
		{
			fr->min.y += (keycode == DOWN_ARROW) ? -mov : mov;
			fr->max.y += (keycode == DOWN_ARROW) ? -mov : mov;
		}
		else
		{
			fr->min.x += (keycode == RIGHT_ARROW) ? -mov : mov;
			fr->max.x += (keycode == RIGHT_ARROW) ? -mov : mov;
		}
		clear_and_draw(fr);
	}
	return (0);
}

void	keys(int keycode, t_fr *fr)
{
	if (keycode == M)
		fr->id_set = 1;
	if (keycode == V)
		fr->bpp = 1;
	if (keycode == B)
		fr->bpp = 0;
	if (keycode == J)
		julia(fr);
	if (keycode == T)
		julia1(fr);
	if (keycode == Y)
		julia2(fr);
	if (keycode == U)
		julia3(fr);
	clear_and_draw(fr);
}

int		keys_hook(int keycode, t_fr *fr)
{
	keys(keycode, fr);
	if (keycode == A)
		fr->id_set = 2;
	if (keycode == Q)
		fr->color = 0x2211FF;
	if (keycode == W)
		fr->color = 0xFFFFFF;
	if (keycode == ESC)
		exit_hook(fr);
	if (keycode == C)
	{
		fr->max.x = 2;
		fr->min.x = -2;
		fr->max.y = 2;
		fr->min.y = -2;
		fr->itr = 250;
		fr->color = 0xFFFFFF;
		clear_and_draw(fr);
	}
	return (keys_move(keycode, fr));
}
