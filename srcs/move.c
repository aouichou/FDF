/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:18:14 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/01 04:30:50 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	altitude(t_segmnt *segmnt, int scale_factor)
{
	segmnt->start.x *= scale_factor;
	segmnt->start.y *= scale_factor;
	segmnt->end.x *= scale_factor;
	segmnt->end.y *= scale_factor;
}

void	translate(t_segmnt *segmnt, int move_x, int move_y)
{
	segmnt->start.x += move_x;
	segmnt->start.y += move_y;
	segmnt->end.x += move_x;
	segmnt->end.y += move_y;
}

void	transform(t_cam *cam, t_segmnt *segmnt)
{
	altitude(segmnt, cam->scale);
	translate(segmnt, cam->move_x, cam->move_y);
}
