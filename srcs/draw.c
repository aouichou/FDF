/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:25:07 by aouichou          #+#    #+#             */
/*   Updated: 2022/07/01 04:09:16 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clear_image(t_image *image, int image_size)
{
	int			x;
	int			y;
	t_main_fdf	*ptr;

	ptr = ft_get_ptr();
	ft_bzero(image->buffer, image_size);
	y = 0;
	while (y < ptr->res_y)
	{
		x = 0;
		while (x < ptr->res_x)
		{
			pixel_to_image(image, x, y, BACKGROUND_DEFAULT);
			x++;
		}
		y++;
	}
}

void	pixel_to_image(t_image *image, float x, float y, int color)
{
	int	pixel;

	pixel = ((int)y * image->segmnt_bits) + ((int)x * 4);
	if (image->endian == 1)
	{
		image->buffer[pixel + 0] = (color >> 24);
		image->buffer[pixel + 1] = (color >> 16) & 0xff;
		image->buffer[pixel + 2] = (color >> 8) & 0xff;
		image->buffer[pixel + 3] = (color) & 0xff;
	}
	else if (image->endian == 0)
	{
		image->buffer[pixel + 0] = (color) & 0xff;
		image->buffer[pixel + 1] = (color >> 8) & 0xff;
		image->buffer[pixel + 2] = (color >> 16) & 0xff;
		image->buffer[pixel + 3] = (color >> 24);
	}
}

void	bresenham(t_main_fdf *ptr, t_p start, t_p end)
{
	float	x_step;
	float	y_step;
	int		max_steps;
	int		i;
	t_color	*color;

	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_steps = (int)ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max_steps;
	y_step /= max_steps;
	color = color_init(start, end);
	if (!color)
		ft_error("init color");
	i = 0;
	while (i < max_steps)
	{
		start.color = get_color(color, i++, max_steps);
		if (start.x > 0 && start.y > 0 && start.x < ptr->res_x && start.y < \
				ptr->res_y)
			pixel_to_image(ptr->image, start.x, start.y, start.color);
		start.x += x_step;
		start.y += y_step;
	}
	free(color);
}
