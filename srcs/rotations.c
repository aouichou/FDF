/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:21:43 by aouichou          #+#    #+#             */
/*   Updated: 2022/06/30 02:27:48 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_z(t_segmnt *segmnt, double angle)
{
	t_p	new_start;
	t_p	new_end;

	new_start.x = segmnt->start.x * cos(angle) - segmnt->start.y * sin(angle);
	new_start.y = segmnt->start.x * sin(angle) + segmnt->start.y * cos(angle);
	segmnt->start.x = new_start.x;
	segmnt->start.y = new_start.y;
	new_end.x = segmnt->end.x * cos(angle) - segmnt->end.y * sin(angle);
	new_end.y = segmnt->end.x * sin(angle) + segmnt->end.y * cos(angle);
	segmnt->end.x = new_end.x;
	segmnt->end.y = new_end.y;
}

void	rotate_y(t_segmnt *segmnt, double angle)
{
	t_p	new_start;
	t_p	new_end;

	new_start.x = segmnt->start.x * cos(angle) + segmnt->start.z * sin(angle);
	new_start.z = -segmnt->start.x * sin(angle) + segmnt->start.z * cos(angle);
	segmnt->start.x = new_start.x;
	segmnt->start.z = new_start.z;
	new_end.x = segmnt->end.x * cos(angle) + segmnt->end.z * sin(angle);
	new_end.z = -segmnt->end.x * sin(angle) + segmnt->end.z * cos(angle);
	segmnt->end.x = new_end.x;
	segmnt->end.z = new_end.z;
}

void	rotate_x(t_segmnt *segmnt, double angle)
{
	t_p	new_start;
	t_p	new_end;

	new_start.y = segmnt->start.y * cos(angle) - segmnt->start.z * sin(angle);
	new_start.z = segmnt->start.y * sin(angle) + segmnt->start.z * cos(angle);
	segmnt->start.y = new_start.y;
	segmnt->start.z = new_start.z;
	new_end.y = segmnt->end.y * cos(angle) - segmnt->end.z * sin(angle);
	new_end.z = segmnt->end.y * sin(angle) + segmnt->end.z * cos(angle);
	segmnt->end.y = new_end.y;
	segmnt->end.z = new_end.z;
}

void	rotate(t_cam *cam, t_segmnt *segmnt)
{
	rotate_x(segmnt, cam->alpha);
	rotate_y(segmnt, cam->beta);
	rotate_z(segmnt, cam->gamma);
}
