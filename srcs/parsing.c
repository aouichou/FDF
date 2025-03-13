/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 02:34:22 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/03 00:00:50 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

void	ft_fill_point(char *point, t_map *map, int x, int y)
{
	char	**tab;

	map->map_coords[x][y].x = (float)x;
	map->map_coords[x][y].y = (float)y;
	if (ft_strchr(point, ','))
	{
		tab = ft_split(point, ',');
		map->map_coords[x][y].z = (float)ft_atoi(tab[0]);
		map->map_coords[x][y].color = \
			ft_atoi_base(tab[1], HEXADECIMAL_BASE);
		ft_free_tab(tab);
	}
	else
	{
		map->map_coords[x][y].z = (float)ft_atoi(point);
		map->map_coords[x][y].color = -1;
	}
	if (map->map_coords[x][y].z > map->mx_h)
		map->mx_h = map->map_coords[x][y].z;
	if (map->map_coords[x][y].z < map->mn_h)
		map->mn_h = map->map_coords[x][y].z;
}

void	ft_fill(char *map_name, t_map *map)
{
	int		fd;
	char	*line;
	char	**tab;
	int		coord[2];

	fd = open(map_name, O_RDONLY, 0);
	coord[1] = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		tab = ft_split(line, ' ');
		coord[0] = 0;
		while (coord[0] < map->mx_x)
		{
			ft_fill_point(tab[coord[0]], map, coord[0], coord[1]);
			coord[0]++;
		}
		ft_free_tab(tab);
		free(line);
		coord[1]++;
	}
	close(fd);
}

int	ft_get_x(t_main_fdf *ptr, t_map *map, char *map_name)
{
	int		i;
	int		j;
	char	*line;

	ptr->fd = open(map_name, O_RDONLY);
	if (ptr->fd < 0)
		ft_error("open map file");
	line = get_next_line(ptr->fd);
	if (!line)
		return (0);
	i = ft_count_tab(line, ' ');
	free(line);
	while (1)
	{
		j = 0;
		line = get_next_line(ptr->fd);
		if (line == NULL)
			break ;
		j = ft_count_tab(line, ' ');
		if (i != j)
			ft_error_map(map, map_name, line);
		free(line);
	}
	close(ptr->fd);
	return (i);
}

int	ft_get_y(t_main_fdf *ptr, char *map_name)
{
	int		x;
	char	*line;

	x = 0;
	ptr->fd = open(map_name, O_RDONLY);
	if (ptr->fd < 0)
		ft_error("open map file");
	line = get_next_line(ptr->fd);
	while (line)
	{
		x++;
		free(line);
		line = get_next_line(ptr->fd);
	}
	close(ptr->fd);
	return (x);
}

void	ft_parsing(int ac, char **av)
{
	int			i;
	t_map		*map;
	t_main_fdf	*ptr;

	i = 0;
	ptr = ft_get_ptr();
	while (++i < ac)
	{
		map = init_map(av[i]);
		if (!(map))
			ft_error("malloc map");
		map->mx_x = ft_get_x(ptr, map, av[i]);
		map->mx_y = ft_get_y(ptr, av[i]);
		map->map_coords = init_coords(map->mx_x, map->mx_y);
		if (!(map->map_coords))
			ft_error("malloc map");
		if (!(ptr->map_head))
			ptr->map_head = map;
		else
			ft_add_to_lst(ptr, map);
		ft_fill(av[i], map);
		center_map(map);
	}
}
