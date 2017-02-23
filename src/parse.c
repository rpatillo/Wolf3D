/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 10:42:50 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/12 16:56:05 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int			count_height(char *map)
{
	int		fd;
	int		i;
	char	buf;

	i = 0;
	if ((fd = open(map, O_RDONLY)) < 0)
	{
		ft_putendl("No map, empty window.");
		exit (0);
	}
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			i++;
	}
	close(fd);
	return (i);
}

int			sub_parse(int fd, t_env *e)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (!(e->map[i] = (int *)malloc(sizeof(int) * (ft_strlen(line)))))
			return (0);
		e->temp = line;
		j = 0;
		while (*(e->temp) != '\0')
		{
			e->map[i][j] = *(e->temp) - '0';
			(e->temp)++;
			j++;
		}
		i++;
		free(line);
	}
	return (0);
}

int			parsemap(char **av, t_env *e)
{
	int		fd;

	e->hei = count_height(av[1]);
	if (!(e->map = (int **)malloc(sizeof(int *) * e->hei)))
	{
		ft_putstr("Malloc Error.");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) > 0)
		sub_parse(fd, e);
	close(fd);
	return (0);
}
