/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:02:29 by aouichou          #+#    #+#             */
/*   Updated: 2022/06/30 23:57:06 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_main_fdf	*ft_get_ptr(void)
{
	static t_main_fdf	*ptr = NULL;

	if (!ptr)
	{
		ptr = (t_main_fdf *)malloc(sizeof(t_main_fdf));
		if (!(ptr))
			return (NULL);
	}
	return (ptr);
}

void	ft_add_to_lst(t_main_fdf *ptr, t_map *link)
{
	t_map	*tmp;

	tmp = ptr->map_head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = link;
	link->previous = tmp;
}

float	ft_abs(float nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	ft_min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
