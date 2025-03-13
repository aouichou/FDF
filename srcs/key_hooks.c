/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:13:06 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/03 01:47:38 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	key_project(int keycode, t_main_fdf *ptr)
{
	if (keycode == KEY_P)
		ptr->cam->projection = PERSPECTIVE;
	else if (keycode == KEY_I)
		ptr->cam->projection = ISOMETRIC;
	else if (keycode == KEY_O)
		ptr->cam->projection = TOP;
}

static void	key_rotate(int keycode, t_main_fdf *ptr)
{
	if (keycode == NUMPAD_7)
		ptr->cam->alpha -= (5 * ANG_1);
	else if (keycode == NUMPAD_9)
		ptr->cam->alpha += (5 * ANG_1);
	else if (keycode == NUMPAD_4)
		ptr->cam->gamma -= (5 * ANG_1);
	else if (keycode == NUMPAD_6)
		ptr->cam->gamma += (5 * ANG_1);
	else if (keycode == NUMPAD_1)
		ptr->cam->beta -= (5 * ANG_1);
	else if (keycode == NUMPAD_3)
		ptr->cam->beta += (5 * ANG_1);
}

static void	key_zoom(int keycode, t_main_fdf *ptr)
{
	if (keycode == KEY_PLUS)
	{
		if (ptr->map_head->next)
			ptr->map_head = ptr->map_head->next;
	}
	else if (keycode == KEY_MINUS)
	{
		if (ptr->map_head->previous)
			ptr->map_head = ptr->map_head->previous;
	}
	else if (keycode == KEY_Z && ptr->cam->scale_z > -1)
		ptr->cam->scale_z -= 0.1;
	else if (keycode == KEY_X && ptr->cam->scale_z < 1)
		ptr->cam->scale_z += 0.1;
}

static void	key_translate_color(int keycode, t_main_fdf *ptr)
{
	if (keycode == KEY_RIGHT)
		ptr->cam->move_x += 10;
	else if (keycode == KEY_LEFT)
		ptr->cam->move_x -= 10;
	else if (keycode == KEY_DOWN)
		ptr->cam->move_y += 10;
	else if (keycode == KEY_UP)
		ptr->cam->move_y -= 10;
	else if (keycode == KEY_Q)
	{
		if (ptr->cam->color_type == 1)
			ptr->cam->color_type = 2;
		else
			ptr->cam->color_type = 1;
	}
}

int	ft_key_hook(int keycode, t_main_fdf *ptr)
{
	if (keycode == KEY_ESC)
		ft_exit();
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT || keycode == KEY_UP \
		|| keycode == KEY_DOWN || keycode == KEY_Q)
		key_translate_color(keycode, ptr);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS || keycode == KEY_Z \
		|| keycode == KEY_X)
		key_zoom(keycode, ptr);
	else if (keycode == NUMPAD_4 || keycode == NUMPAD_7 || keycode == NUMPAD_6 \
		|| keycode == NUMPAD_1 || keycode == NUMPAD_9 || keycode == NUMPAD_3)
		key_rotate(keycode, ptr);
	else if (keycode == KEY_P || keycode == KEY_I || keycode == KEY_O)
		key_project(keycode, ptr);
	else if (keycode == KEY_SPACE)
	{
		if (ptr->cam->color_pallet == FALSE)
			ptr->cam->color_pallet = TRUE;
		else
			ptr->cam->color_pallet = FALSE;
	}
	else if (keycode == KEY_R)
		reset_cam(ptr);
	renderer(ptr);
	return (0);
}
