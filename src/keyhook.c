/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 13:21:43 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/12 16:08:08 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		key_hook(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_xpm_file_to_image(e->mlx, "xpm/milky.xpm", &e->sx, &e->sy);
	if (e->f_up == 1)
	{
		if (e->map[(int)(e->posx + e->dirx)][(int)e->posy] == 0)
			e->posx += e->dirx / 4;
		if (e->map[(int)e->posx][(int)(e->posy + e->diry)] == 0)
			e->posy += e->diry / 4;
	}
	if (e->f_up == -1)
	{
		if (e->map[(int)(e->posx - e->dirx)][(int)e->posy] == 0)
			e->posx -= e->dirx / 4;
		if (e->map[(int)e->posx][(int)(e->posy - e->diry)] == 0)
			e->posy -= e->diry / 4;
	}
	key_hook2(e);
	return (0);
}

int		key_hook2(t_env *e)
{
	if (e->f_turn == 1)
	{
		e->olddirx = e->dirx;
		e->dirx = e->dirx * cos(0.09) - e->diry * sin(0.09);
		e->diry = e->olddirx * sin(0.09) + e->diry * cos(0.09);
		e->oldplanex = e->planex;
		e->planex = e->planex * cos(0.09) - e->planey * sin(0.09);
		e->planey = e->oldplanex * sin(0.09) + e->planey * cos(0.09);
	}
	if (e->f_turn == -1)
	{
		e->olddirx = e->dirx;
		e->dirx = e->dirx * cos(0.09) - e->diry * sin(-0.09);
		e->diry = e->olddirx * sin(-0.09) + e->diry * cos(0.09);
		e->oldplanex = e->planex;
		e->planex = e->planex * cos(0.09) - e->planey * sin(-0.09);
		e->planey = e->oldplanex * sin(-0.09) + e->planey * cos(0.09);
	}
	wolf(e);
	get_expose(e);
	return (0);
}
