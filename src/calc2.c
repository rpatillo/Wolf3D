/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 12:39:18 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/14 11:55:40 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int			wolf6(t_env *e, int i)
{
	if (e->side == 0 && e->raydirx > 0 && e->map[e->mapx][e->mapy] != 5)
		e->color = 0x800000;
	else if (e->side == 1 && e->raydiry > 0 && e->map[e->mapx][e->mapy] != 5)
		e->color = 0x666600;
	else if (e->side == 0 && e->raydirx < 0 && e->map[e->mapx][e->mapy] != 5)
		e->color = 0x660066;
	else if (e->side == 1 && e->raydiry > 0 && e->map[e->mapx][e->mapy] != 5)
		e->color = 0x00FF00;
	else if (e->map[e->mapx][e->mapy] == 5)
		e->color = 0x333333;
	else
		e->color = 0x000066;
	wolf7(e, i);
	return (0);
}

int			wolf7(t_env *e, int i)
{
	while (e->drawstart < e->drawend)
	{
		pixel_put_to_image(e->color, e, i, e->drawstart);
		e->drawstart++;
	}
	return (0);
}
