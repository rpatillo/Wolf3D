/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 14:11:16 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/12 16:08:27 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int			ft_k_press(int keycode, t_env *e)
{
	(keycode == ESC) ? exit(0) : keycode;
	if (keycode == 15)
	{
		initwolf(e);
		freemap(e);
		parsemap(e->av, e);
	}
	if (keycode == 13)
		e->f_up = 1;
	else if (keycode == 1)
		e->f_up = -1;
	else if (keycode == 2)
		e->f_turn = 1;
	else if (keycode == 0)
		e->f_turn = -1;
	if (keycode == 11)
	{
		if ((e->map)[e->mapx][e->mapy] == 5 &&
			(e->sidedistx < 2 || e->sidedisty < 2))
			e->map[e->mapx][e->mapy] = 0;
	}
	return (0);
}

int			ft_k_release(int keycode, t_env *e)
{
	if ((keycode == 13) || (keycode == 1))
		e->f_up = 0;
	else if ((keycode == 2) || (keycode == 0))
		e->f_turn = 0;
	return (0);
}
