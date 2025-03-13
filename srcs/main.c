/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:00:14 by aouichou          #+#    #+#             */
/*   Updated: 2022/06/30 04:41:17 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_screen_size(t_main_fdf **ptr)
{
	char	*x;
	char	*y;
	char	*line;

	(*ptr)->fd = open("res.txt", O_RDONLY);
	if (((*ptr)->fd) < 0)
		ft_error("open res.txt");
	line = get_next_line((*ptr)->fd);
	x = ft_strtok(line, 'x');
	y = ft_strrtok(line, 'x');
	(*ptr)->res_x = ft_atoi(x);
	(*ptr)->res_y = ft_atoi(y) - 120;
	free(x);
	free(y);
	free(line);
	close((*ptr)->fd);
}

void	ft_ptr_init(t_main_fdf **ptr)
{
	(*ptr)->fd = 0;
	(*ptr)->mlx = NULL;
	(*ptr)->win = NULL;
	(*ptr)->image = NULL;
	(*ptr)->res_x = 0;
	(*ptr)->res_y = 0;
	(*ptr)->map_head = NULL;
	(*ptr)->cam = NULL;
}

int	main(int ac, char **av)
{
	t_main_fdf	*ptr;

	if (ac == 1)
		ft_error("usage ./fdf [map1.fdf] [map2.fdf] ... ");
	else if (ac > 1)
	{
		ptr = ft_get_ptr();
		ft_ptr_init(&ptr);
		ft_screen_size(&ptr);
		ft_parsing(ac, av);
		ft_mlx(ptr);
	}
	return (0);
}
