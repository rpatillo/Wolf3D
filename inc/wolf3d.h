/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 10:09:16 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/12 16:49:58 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/inc/libft.h"
# include "../minilibx_macos/mlx.h"
# include "struct.h"

# define WIDTH 1280
# define HEIGHT	720
# define ESC 53

int		verifmap(char **av);
int		count_height(char *map);
int		sub_parse(int fd, t_env *e);
int		parsemap(char **av, t_env *e);
void	pixel_put_to_image(unsigned long img_color, t_env *e, int x, int y);
void	initwolf(t_env *e);
int		key_hook(t_env *e);
int		wolf(t_env *e);
int		wolf2(t_env *e, int i);
int		wolf3(t_env *e, int i);
int		wolf4(t_env *e, int i);
int		wolf5(t_env *e, int i);
int		wolf6(t_env *e, int i);
int		wolf7(t_env *e, int i);
int		get_expose(t_env *e);
int		ft_k_press(int keycode, t_env *e);
int		ft_k_release(int keycode, t_env *e);
int		key_hook2(t_env *e);
int		print_options();
int		freemap(t_env *e);
int		ft_error(int i);

#endif
