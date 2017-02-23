/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 10:05:59 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/12 16:59:52 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	initwolf(t_env *e)
{
	e->posx = 2;
	e->posy = 2;
	e->dirx = 1;
	e->diry = 0;
	e->planex = 0;
	e->planey = 0.66;
	e->f_up = 0;
	e->f_turn = 0;
	e->sx = HEIGHT;
	e->sy = WIDTH;
}

int		freemap(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->hei)
	{
		free(e->map[i]);
		i++;
	}
	free(e->map);
	return (0);
}

int		print_options(void)
{
	ft_putendl("-> Options for Wolf3D.");
	ft_putchar('\n');
	ft_putendl("- W/S A/D to move.");
	ft_putendl("- B to destroy grey block.");
	ft_putendl("- R to restart level.");
	ft_putchar('\n');
	ft_putendl("++ There's a sky up in there !    ++");
	ft_putendl("++ Can't go through walls.        ++");
	ft_putendl("++ But sometimes, it's invisible. ++");
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	e.av = av;
	if (ac != 2)
		ft_error(1);
	if (verifmap(av) != 1)
		ft_error(2);
	parsemap(av, &e);
	e.mlx = mlx_init();
	print_options();
	if (!(e.img = mlx_xpm_file_to_image
		(e.mlx, "xpm/milky.xpm", &e.sx, &e.sy)))
		exit(-1);
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Wolf3D");
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.sline, &e.endian);
	initwolf(&e);
	wolf(&e);
	mlx_hook(e.win, 2, 1, ft_k_press, &e);
	mlx_hook(e.win, 3, 2, ft_k_release, &e);
	mlx_expose_hook(e.win, &get_expose, &e);
	mlx_loop_hook(e.mlx, key_hook, &e);
	mlx_loop(e.mlx);
	freemap(&e);
	return (0);
}
