/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpatillo <rpatillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 16:42:29 by rpatillo          #+#    #+#             */
/*   Updated: 2015/06/12 16:50:19 by rpatillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int		verifmap(char **av)
{
	int		i;
	int		j;
	char	*temp;
	char	*verif;

	verif = ".w3d";
	temp = av[1];
	i = ft_strlen(av[1]) - 4;
	j = 0;
	while (i < ft_strlen(av[1]))
	{
		if (temp[i] == verif[j])
		{
			j++;
		}
		else
			return (0);
		i++;
	}
	if (temp[i] == '\0')
		return (1);
	else
		return (0);
}

int		ft_error(int i)
{
	if (i == 1)
	{
		ft_putendl("Please, choose a map in ./maps.");
		exit (0);
	}
	if (i == 2)
	{
		ft_putendl("You need a .w3d file, look in ./maps.");
		exit (0);
	}
	return (0);
}
