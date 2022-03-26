/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftonita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 06:35:57 by ftonita           #+#    #+#             */
/*   Updated: 2022/03/26 06:36:04 by ftonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_to_center(t_xyz ***map, t_xyz *center)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			map[i][j]->x = map[i][j]->x - center->x;
			map[i][j]->y = map[i][j]->y - center->y;
			map[i][j]->z = map[i][j]->z - center->z;
			j++;
		}
		i++;
	}
}

void	set_size(t_xyz *point, double line_len)
{
	point->x *= line_len;
	point->y *= line_len;
	point->z *= line_len;
}
