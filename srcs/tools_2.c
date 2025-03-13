/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:13:28 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/03 03:47:31 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	center_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->mx_y)
	{
		x = 0;
		while (x < map->mx_x)
		{
			map->map_coords[x][y].x -= map->mx_x / 2;
			map->map_coords[x][y].y -= map->mx_y / 2;
			x++;
		}
		y++;
	}
}

float	scale_to_fit(t_map *map)
{
	t_main_fdf	*ptr;
	float		scale_x;
	float		scale_y;
	float		scale;

	ptr = ft_get_ptr();
	scale_x = ptr->res_x / map->mx_x;
	scale_y = ptr->res_y / map->mx_y;
	scale = ft_min(scale_x, scale_y);
	if (scale < 4)
		return (2);
	return (scale / 2);
}

void	reset_cam(t_main_fdf *ptr)
{
	ptr->cam->projection = ISOMETRIC;
	ptr->cam->scale = scale_to_fit(ptr->map_head);
	ptr->cam->scale_z = 1;
	ptr->cam->move_x = ptr->res_x / 2;
	ptr->cam->move_y = ptr->res_y / 2;
	ptr->cam->alpha = 0;
	ptr->cam->beta = 0;
	ptr->cam->gamma = 0;
}

int	ft_count_tab(char *line, char c)
{
	int		count;
	char	**tab;

	count = 0;
	tab = ft_split(line, c);
	while (tab[count])
		count++;
	ft_free_tab(tab);
	return (count);
}
