/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 07:54:30 by aouichou          #+#    #+#             */
/*   Updated: 2022/06/30 08:00:19 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_mouse_hook(int keycode, int x, int y, t_main_fdf *ptr)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		ptr->cam->scale += 1;
	if (keycode == 5)
		ptr->cam->scale -= 1;
	renderer(ptr);
	return (0);
}
