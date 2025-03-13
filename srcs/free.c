/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:51:52 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/02 23:55:09 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_coords(t_p **coordinates, int width)
{
	int		i;

	i = 0;
	while (i < width)
	{
		free(coordinates[i]);
		i++;
	}
	free(coordinates);
}

void	free_map(t_map *map)
{
	t_map	*tmp;

	if (map)
	{
		while (map->previous)
			map = map->previous;
		while (map)
		{
			if (map->map_coords)
				free_coords(map->map_coords, map->mx_x);
			free(map->name);
			tmp = map;
			map = map->next;
			free(tmp);
		}
	}
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
