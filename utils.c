/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftonita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 06:38:20 by ftonita           #+#    #+#             */
/*   Updated: 2022/03/26 06:38:23 by ftonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	i_part(double x)
{
	return ((int)x);
}

void	swap(t_xyz *s, t_xyz *e)
{
	double	temp;

	temp = s->x;
	s->x = e->x;
	e->x = temp;
	temp = s->y;
	s->y = e->y;
	e->y = temp;
}

t_xyz	*point_move(t_xyz *point, t_fdf *fdf)
{
	t_xyz	*new_point;

	new_point = xyz_copy(point);
	set_size(new_point, fdf->scale);
	to_iso(new_point);
	add_shift(new_point, fdf->shift);
	return (new_point);
}

int	choose_color(float z)
{
	if (z < 1)
		return (0xFFFFFF);
	else if (z > 1)
		return (0x00FF00);
	else
		return (0xFF0000);
}
