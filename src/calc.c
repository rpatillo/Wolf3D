/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 12:37:24 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/12 16:39:35 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int			wolf(t_env *e)
{
	int		i;
	int		sx;
	int		sy;

	i = 0;
	sx = -1;
	while (++sx < WIDTH)
	{
		sy = 359;
		while (++sy < HEIGHT)
			pixel_put_to_image(0x004C00, e, sx, sy);
	}
	while (i < WIDTH)
	{
		e->camerax = 2 * i / (double)WIDTH - 1;
		e->rayposx = e->posx;
		e->rayposy = e->posy;
		e->raydirx = e->dirx + e->planex * e->camerax;
		e->raydiry = e->diry + e->planey * e->camerax;
		e->mapx = (int)(e->rayposx);
		e->mapy = (int)(e->rayposy);
		wolf2(e, i);
		i++;
	}
	return (0);
}

int			wolf2(t_env *e, int i)
{
	e->deltadistx = sqrt(1 + (e->raydiry * e->raydiry) /
					(e->raydirx * e->raydirx));
	e->deltadisty = sqrt(1 + (e->raydirx * e->raydirx) /
					(e->raydiry * e->raydiry));
	wolf3(e, i);
	return (0);
}

int			wolf3(t_env *e, int i)
{
	if (e->raydirx < 0)
	{
		e->stepx = -1;
		e->sidedistx = (e->rayposx - e->mapx) * e->deltadistx;
	}
	else
	{
		e->stepx = 1;
		e->sidedistx = (e->mapx + 1.0 - e->rayposx) * e->deltadistx;
	}
	if (e->raydiry < 0)
	{
		e->stepy = -1;
		e->sidedisty = (e->rayposy - e->mapy) * e->deltadisty;
	}
	else
	{
		e->stepy = 1;
		e->sidedisty = (e->mapy + 1.0 - e->rayposy) * e->deltadisty;
	}
	wolf4(e, i);
	return (0);
}

int			wolf4(t_env *e, int i)
{
	e->hit = 0;
	while (e->hit == 0)
	{
		if (e->sidedistx < e->sidedisty)
		{
			e->sidedistx += e->deltadistx;
			e->mapx += e->stepx;
			e->side = 0;
		}
		else
		{
			e->sidedisty += e->deltadisty;
			e->mapy += e->stepy;
			e->side = 1;
		}
		if (e->map[e->mapx][e->mapy] > 0)
			e->hit = 1;
	}
	wolf5(e, i);
	return (0);
}

int			wolf5(t_env *e, int i)
{
	int		lineheight;

	if (e->side == 0)
		e->perpwalldist = fabs((e->mapx - e->rayposx + (1 - e->stepx) / 2)
							/ e->raydirx);
	else
		e->perpwalldist = fabs((e->mapy - e->rayposy + (1 - e->stepy) / 2)
							/ e->raydiry);
	lineheight = abs((int)(HEIGHT / e->perpwalldist));
	e->drawstart = -lineheight / 2 + HEIGHT / 2;
	if (e->drawstart < 0)
		e->drawstart = 0;
	e->drawend = lineheight / 2 + HEIGHT / 2;
	if (e->drawend >= HEIGHT)
		e->drawend = HEIGHT - 1;
	wolf6(e, i);
	return (0);
}
