/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:11:38 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/01 04:31:49 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	perspective(t_segmnt *segmnt)
{
	t_p		new_start;
	t_p		new_end;
	double	z;

	rotate_x(segmnt, 3 * -ANG_45);
	z = segmnt->start.z + segmnt->new_z;
	new_start.x = segmnt->start.x / z;
	new_start.y = segmnt->start.y / z;
	segmnt->start.x = new_start.x;
	segmnt->start.y = -new_start.y;
	z = segmnt->end.z + segmnt->new_z;
	new_end.x = segmnt->end.x / z;
	new_end.y = segmnt->end.y / z;
	segmnt->end.x = new_end.x;
	segmnt->end.y = -new_end.y;
	altitude(segmnt, segmnt->new_z);
}

static void	isometric(t_segmnt *segmnt)
{
	t_p	new_start;
	t_p	new_end;

	new_start.x = (segmnt->start.x - segmnt->start.y) * cos(ANG_30);
	new_start.y = (segmnt->start.x + segmnt->start.y) * sin(ANG_30) - \
		segmnt->start.z;
	segmnt->start.x = new_start.x;
	segmnt->start.y = new_start.y;
	new_end.x = (segmnt->end.x - segmnt->end.y) * cos(ANG_30);
	new_end.y = (segmnt->end.x + segmnt->end.y) * sin(ANG_30) - segmnt->end.z;
	segmnt->end.x = new_end.x;
	segmnt->end.y = new_end.y;
}

void	project(t_cam *cam, t_segmnt *segmnt)
{
	if (cam->projection == ISOMETRIC)
		isometric(segmnt);
	else if (cam->projection == PERSPECTIVE)
		perspective(segmnt);
	else if (cam->projection == TOP)
		return ;
}
