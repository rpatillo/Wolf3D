/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/11 13:14:36 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/12 12:07:12 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "wolf3d.h"

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	char		*temp;
	char		**av;
	int			**map;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			drawstart;
	int			drawend;
	int			color;
	int			len;
	int			hei;
	int			lenline;
	int			endian;
	int			bpp;
	int			sline;
	int			f_up;
	int			f_turn;
	int			sx;
	int			sy;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		olddirx;
	double		planex;
	double		planey;
	double		oldplanex;
	double		camerax;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
}				t_env;

#endif
