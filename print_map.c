/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftonita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 06:37:24 by ftonita           #+#    #+#             */
/*   Updated: 2022/03/26 06:37:30 by ftonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_line(t_line *line)
{
	if (line->end->x > line->start->x)
		line->dx = line->end->x - line->start->x;
	else
		line->dx = line->start->x - line->end->x;
	if (line->end->y > line->start->y)
		line->dy = line->end->y - line->start->y;
	else
		line->dy = line->start->y - line->end->y;
	if (line->dx == 0)
		print_simple_linex(line->start, line->end, line->img, line->color);
	else if (line->dy == 0)
		print_simple_liney(line->start, line->end, line->img, line->color);
	else if (line->dy < line->dx)
		print_line_x(line);
	else
		print_line_y(line);
}

void	print_two_line(t_fdf *fdf, t_line *line, int i, int j)
{
	line->color = choose_color(fdf->map[i][j]->z);
	if (fdf->map[i][j + 1])
	{
		line->start = point_move(fdf->map[i][j], fdf);
		line->end = point_move(fdf->map[i][j + 1], fdf);
		print_line(line);
		free(line->start);
		free(line->end);
	}
	if (fdf->map[i + 1] != NULL)
	{
		line->start = point_move(fdf->map[i][j], fdf);
		line->end = point_move(fdf->map[i + 1][j], fdf);
		print_line(line);
		free(line->start);
		free(line->end);
	}
}

void	print_map(t_fdf *fdf)
{
	int		i;
	int		j;
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	line->img = fdf->img;
	i = 0;
	while (fdf->map[i] != NULL)
	{
		j = 0;
		while (fdf->map[i][j])
		{
			print_two_line(fdf, line, i, j);
			j++;
		}
		i++;
	}
	free(line);
}
