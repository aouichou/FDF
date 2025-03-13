/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:17:55 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/03 03:22:01 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	apply_colors(t_main_fdf *ptr, t_p *point)
{
	if (ptr->cam->color_pallet == FALSE)
	{
		if (point->color == -1)
			point->color = SEGMNT_DEFAULT;
	}
	else if (ptr->cam->color_type == 1)
	{
		if (point->z > 0)
			apply_colors_positif(ptr, point);
		else if (point->z <= 0)
			apply_colors_negatif(ptr, point);
	}
	else if (ptr->cam->color_type == 2)
	{
		if (point->z <= 0)
			apply_topo_colors_negatif(ptr, point);
		if (point->z > 0)
			apply_topo_colors_positif(ptr, point);
	}
}

void	render_segmnt(t_main_fdf *ptr, t_p start, t_p end)
{
	if (start.z >= 0)
		start.z *= ptr->cam->scale_z;
	if (end.z >= 0)
		end.z *= ptr->cam->scale_z;
	apply_colors(ptr, &start);
	apply_colors(ptr, &end);
	ptr->image->segmnt = init_segmnt(start, end);
	if (!(ptr->image->segmnt))
		ft_error("malloc segment");
	rotate(ptr->cam, ptr->image->segmnt);
	project(ptr->cam, ptr->image->segmnt);
	transform(ptr->cam, ptr->image->segmnt);
	bresenham(ptr, ptr->image->segmnt->start, ptr->image->segmnt->end);
	free(ptr->image->segmnt);
}

void	renderer(t_main_fdf *ptr)
{
	int	x;
	int	y;

	clear_image(ptr->image, MAX_PIXEL * 4);
	y = 0;
	while (y < ptr->map_head->mx_y)
	{
		x = 0;
		while (x < ptr->map_head->mx_x)
		{
			if (x < ptr->map_head->mx_x - 1)
				render_segmnt(ptr, ptr->map_head->map_coords[x][y], \
					ptr->map_head->map_coords[x + 1][y]);
			if (y < ptr->map_head->mx_y - 1)
				render_segmnt(ptr, ptr->map_head->map_coords[x][y], \
					ptr->map_head->map_coords[x][y + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->image->image, 0, 0);
	ft_display_menu(ptr);
}

int	handler(t_main_fdf *ptr)
{
	renderer(ptr);
	return (0);
}

void	ft_mlx(t_main_fdf *ptr)
{
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, ptr->res_x, ptr->res_y,
			WINDOW_NAME);
	ptr->image = init_image(ptr);
	if (!(ptr->image))
		ft_error("Can't creat image");
	ptr->cam = init_cam(ptr);
	if (!(ptr->cam))
		ft_error("Can't creat cam");
	renderer(ptr);
	mlx_key_hook(ptr->win, &ft_key_hook, ptr);
	mlx_mouse_hook(ptr->win, &ft_mouse_hook, ptr);
	mlx_hook(ptr->win, 17, 0, &ft_close, ptr);
	mlx_expose_hook(ptr->win, &handler, ptr);
	mlx_loop(ptr->mlx);
}
