/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:50:54 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/03 01:34:31 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*init_map(char *name)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->name = ft_strdup(name);
	map->map_coords = NULL;
	map->mx_x = 0;
	map->mx_y = 0;
	map->mx_h = 0;
	map->mn_h = 0;
	map->next = NULL;
	map->previous = NULL;
	return (map);
}

t_image	*init_image(t_main_fdf *ptr)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->image = mlx_new_image(ptr->mlx, ptr->res_x, ptr->res_y);
	image->buffer = mlx_get_data_addr(image->image, &image->pxl_bits, \
			&image->segmnt_bits, &image->endian);
	image->segmnt = NULL;
	return (image);
}

t_cam	*init_cam(t_main_fdf *ptr)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->projection = ISOMETRIC;
	cam->color_pallet = FALSE;
	cam->color_type = 1;
	cam->scale = scale_to_fit(ptr->map_head);
	cam->scale_z = 1;
	cam->move_x = ptr->res_x / 2;
	cam->move_y = ptr->res_y / 2;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	return (cam);
}

t_segmnt	*init_segmnt(t_p start, t_p end)
{
	t_main_fdf	*ptr;
	t_segmnt	*segmnt;

	ptr = ft_get_ptr();
	segmnt = malloc(sizeof(t_segmnt));
	if (!segmnt)
		return (NULL);
	segmnt->start.x = start.x;
	segmnt->start.y = start.y;
	segmnt->start.z = start.z;
	segmnt->start.color = start.color;
	segmnt->end.x = end.x;
	segmnt->end.y = end.y;
	segmnt->end.z = end.z;
	segmnt->end.color = end.color;
	segmnt->new_z = ft_max((ptr->map_head->mx_h - ptr->map_head->mn_h), \
		ft_max(ptr->map_head->mx_x, ptr->map_head->mx_y));
	return (segmnt);
}

t_p	**init_coords(int mx_x, int mx_y)
{
	t_p	**coords;
	int	i;
	int	j;

	coords = (t_p **)malloc(mx_x * sizeof(t_p *));
	if (!coords)
		return (NULL);
	i = 0;
	while (i < mx_x)
	{
		coords[i] = (t_p *)malloc((mx_y + 1) * sizeof(t_p));
		if (!coords[i])
			return (NULL);
		j = 0;
		while (j < mx_y)
		{
			coords[i][j].x = 0;
			coords[i][j].y = 0;
			coords[i][j].z = 0;
			coords[i][j].color = 0;
			j++;
		}
		i++;
	}
	return (coords);
}
