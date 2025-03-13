/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:28:53 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/03 19:44:29 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static char	*get_projection_name(t_main_fdf *ptr)
{
	char	*projection;

	projection = "";
	if (ptr->cam->projection == ISOMETRIC)
		projection = "Isometric projection";
	else if (ptr->cam->projection == PERSPECTIVE)
		projection = "Perspective projection";
	else if (ptr->cam->projection == TOP)
		projection = "Top down view";
	return (projection);
}

static void	ft_display_menu_projections(t_main_fdf *ptr, int y)
{
	void	*mlx;
	void	*win;

	mlx = ptr->mlx;
	win = ptr->win;
	mlx_string_put(mlx, win, 10, y += 45, C_WHITE, \
				"To change projection view:");
	mlx_string_put(mlx, win, 10, y += 30, C_TEXT, "Isometric   : 'I'");
	mlx_string_put(mlx, win, 10, y += 20, C_TEXT, "Perspective : 'P'");
	mlx_string_put(mlx, win, 10, y += 20, C_TEXT, "Top View    : 'O'");
	mlx_string_put(mlx, win, 10, y += 20, C_TEXT, "Reset view  : 'R'");
}

void	ft_display_menu(t_main_fdf *ptr)
{
	int		y;
	char	*projection;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = ptr->mlx;
	win = ptr->win;
	projection = get_projection_name(ptr);
	mlx_string_put(mlx, win, 10, y += 20, C_CYAN, ptr->map_head->name);
	mlx_string_put(mlx, win, 10, y += 30, C_BLUEY, projection);
	mlx_string_put(mlx, win, 10, y += 35, C_TEXT, "Zoom         : mouse wheel");
	mlx_string_put(mlx, win, 10, y += 20, C_TEXT, "Move         : arrow keys");
	mlx_string_put(mlx, win, 10, y += 20, C_TEXT, "Rotate X     : '7' & '9'");
	mlx_string_put(mlx, win, 10, y += 20, C_TEXT, "Rotate Y     : '1' & '3'");
	mlx_string_put(mlx, win, 10, y += 20, C_TEXT, "Rotate Z     : '4' & '6'");
	mlx_string_put(mlx, win, 10, y += 20, C_TEXT, "Altitude Z   : 'Z' & 'X'");
	mlx_string_put(mlx, win, 10, y += 20, C_TEXT, "Next map     : 'plus'");
	mlx_string_put(mlx, win, 10, y += 20, C_TEXT, "Previous map : 'minus'");
	mlx_string_put(mlx, win, 10, y += 20, C_TEXT, "Colors       : 'SPACE'");
	mlx_string_put(mlx, win, 10, y += 20, C_TEXT, "Change colors: 'Q'");
	mlx_string_put(mlx, win, 10, y += 20, C_TEXT, "Close window : 'ESC'");
	ft_display_menu_projections(ptr, y);
}
