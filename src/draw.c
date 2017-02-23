/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 14:39:38 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/10 17:20:18 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	pixel_put_to_image(unsigned long img_color, t_env *e, int x, int y)
{
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		color1 = (img_color & 0xFF0000) >> 16;
		color2 = (img_color & 0xFF00) >> 8;
		color3 = (img_color & 0xFF);
		e->data[y * e->sline + x * e->bpp / 8] = color3;
		e->data[y * e->sline + x * e->bpp / 8 + 1] = color2;
		e->data[y * e->sline + x * e->bpp / 8 + 2] = color1;
	}
}

int		get_expose(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
