/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_topography_colors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 03:20:44 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/03 03:22:54 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	apply_topo_colors_positif(t_main_fdf *ptr, t_p *point)
{
	t_color	*col;

	if (point->z <= (0.3 * ptr->map_head->mx_x))
	{
		col = starting_color_init(0x06b41b, 0x185421);
		point->color = get_color(col, ft_abs(point->z), \
			ft_abs(ptr->map_head->mx_h));
		free(col);
	}
	else if ((point->z >= (0.3 * ptr->map_head->mx_x)) \
			&& (point->z <= (0.6 * ptr->map_head->mx_x)))
	{
		col = starting_color_init(0x185421, 0x533b2a);
		point->color = get_color(col, ft_abs(point->z), \
			ft_abs(ptr->map_head->mx_h));
		free(col);
	}
	else if (point->z > (0.6 * ptr->map_head->mx_x))
	{
		col = starting_color_init(0x533b2a, 0xffffff);
		point->color = get_color(col, ft_abs(point->z), \
			ft_abs(ptr->map_head->mx_h));
		free(col);
	}
}

void	apply_topo_colors_negatif(t_main_fdf *ptr, t_p *point)
{
	t_color	*col;

	if (point->z <= (0.3 * ptr->map_head->mx_x))
	{
		col = starting_color_init(0x0084f9, 0x1e429f);
		point->color = get_color(col, ft_abs(point->z), \
			ft_abs(ptr->map_head->mx_h));
		free(col);
	}
	else if ((point->z >= (0.3 * ptr->map_head->mx_x)) \
			&& (point->z <= (0.6 * ptr->map_head->mx_x)))
	{
		col = starting_color_init(0x1e429f, 0x002073);
		point->color = get_color(col, ft_abs(point->z), \
			ft_abs(ptr->map_head->mx_h));
		free(col);
	}
	else if (point->z > (0.6 * ptr->map_head->mx_x))
	{
		col = starting_color_init(0x002073, 0x000000);
		point->color = get_color(col, ft_abs(point->z), \
			ft_abs(ptr->map_head->mx_h));
		free(col);
	}
}
