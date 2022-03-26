/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftonita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 06:36:49 by ftonita           #+#    #+#             */
/*   Updated: 2022/03/26 06:37:05 by ftonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_simple_linex(t_xyz *start_point, t_xyz *end_point,
		t_img *img, int color)
{
	if (end_point->y < start_point->y)
		swap(start_point, end_point);
	while (start_point->y <= end_point->y)
	{
		put_pixel_img(img, (int)roundl(start_point->x),
			(int)roundl(start_point->y), color);
		start_point->y++;
	}
}

void	print_simple_liney(t_xyz *start_point, t_xyz *end_point,
		t_img *img, int color)
{
	if (end_point->x < start_point->x)
		swap(start_point, end_point);
	while (start_point->x <= end_point->x)
	{
		put_pixel_img(img, (int)roundl(start_point->x),
			(int)roundl(start_point->y), color);
		start_point->x++;
	}
}

void	print_line_x(t_line *line)
{
	double	grad;
	double	temp;

	grad = (double)line->dy / (double)line->dx;
	if (line->end->x < line->start->x)
		swap(line->start, line->end);
	if (line->end->y < line->start->y)
		grad = -grad;
	temp = line->start->y + grad;
	put_pixel_img(line->img, line->start->x, line->start->y, line->color);
	line->start->x = line->start->x + 1;
	while (line->start->x <= line->end->x)
	{
		put_pixel_img(line->img, line->start->x, i_part(temp), line->color);
		temp += grad;
		(line->start->x)++;
	}
	put_pixel_img(line->img, line->end->x, line->end->y, line->color);
}

void	print_line_y(t_line *line)
{
	double	grad;
	double	temp;

	grad = (double)line->dx / (double)line->dy;
	if (line->end->y < line->start->y)
		swap(line->start, line->end);
	if (line->end->x < line->start->x)
		grad = -grad;
	temp = line->start->x + grad;
	put_pixel_img(line->img, line->start->x, line->start->y, line->color);
	line->start->y = line->start->y + 1;
	while (line->start->y < line->end->y)
	{
		put_pixel_img(line->img, i_part(temp), line->start->y, line->color);
		temp += grad;
		(line->start->y)++;
	}
	put_pixel_img(line->img, line->end->x, line->end->y, line->color);
}
