/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouichou <aouichou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:22:39 by aouichou          #+#    #+#             */
/*   Updated: 2022/06/24 19:23:40 by aouichou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(const char *s, int c)
{
	int		z;
	int		y;
	char	*dst;

	z = 0;
	y = -1;
	if (s && c)
	{
		while (s[z])
		{
			if (s[z] == c)
				y = z;
			z++;
		}
		dst = (char *)malloc(sizeof(char) * z + 1);
		if ((c == '\0' && y == -1) || !(dst))
			return (NULL);
		z = -1;
		while (++z < y)
			dst[z] = s[z];
		dst[z] = '\0';
		return (dst);
	}
	return (NULL);
}
