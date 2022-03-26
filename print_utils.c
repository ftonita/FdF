/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftonita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 06:37:49 by ftonita           #+#    #+#             */
/*   Updated: 2022/03/26 06:37:51 by ftonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_img(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x > 999 || y > 999 || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_xyz	*xyz_copy(t_xyz *p)
{
	t_xyz	*copy;

	copy = (t_xyz *)malloc(sizeof(t_xyz));
	copy->x = p->x;
	copy->y = p->y;
	copy->z = p->z;
	return (copy);
}

void	add_shift(t_xyz *p, t_xyz *shift)
{
	p->x += shift->x;
	p->y += shift->y;
	p->z += shift->z;
}

void	to_iso(t_xyz *p)
{
	int	temp_x;
	int	temp_y;

	temp_x = p->x;
	temp_y = p->y;
	p->x = (temp_x - temp_y) * cos(0.6);
	p->y = -p->z + (temp_x + temp_y) * sin(0.7);
}
