/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 03:18:37 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/03 03:19:16 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	apply_colors_positif(t_main_fdf *ptr, t_p *point)
{
	t_color	*col;

	col = NULL;
	col = starting_color_init(C_BLUE, C_LIGHT_GREEN);
	point->color = get_color(col, ft_abs(point->z), \
			ft_abs(ptr->map_head->mx_h));
	free(col);
}

void	apply_colors_negatif(t_main_fdf *ptr, t_p *point)
{
	t_color	*col;

	col = NULL;
	col = starting_color_init(C_DRK_BLUE, C_VIOLET);
	point->color = get_color(col, ft_abs(point->z), \
			ft_abs(ptr->map_head->mx_h));
	free(col);
}
