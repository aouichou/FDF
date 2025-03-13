/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:54:16 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/02 23:58:14 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_exit(void)
{
	t_main_fdf	*ptr;

	ptr = ft_get_ptr();
	if (ptr)
	{
		if (ptr->map_head)
			free_map(ptr->map_head);
		if (ptr->image)
		{
			mlx_destroy_image(ptr->mlx, ptr->image->image);
			if (ptr->image)
				free(ptr->image);
		}
		if (ptr->cam)
			free(ptr->cam);
		if (ptr->win)
			mlx_destroy_window(ptr->mlx, ptr->win);
		if (ptr->mlx)
		{
			mlx_destroy_display(ptr->mlx);
			free(ptr->mlx);
		}
		free(ptr);
	}
	exit(0);
}

int	ft_close(void *param)
{
	(void)param;
	ft_exit();
	return (0);
}

void	ft_error(char *error)
{
	ft_putstr_fd("error: ", 2);
	ft_putendl_fd(error, 2);
	ft_exit();
}

void	ft_error_map(t_map *map, char *map_name, char *line)
{
	free(line);
	free_map(map);
	ft_error(map_name);
}
