/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftonita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 06:35:25 by ftonita           #+#    #+#             */
/*   Updated: 2022/03/26 06:35:31 by ftonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	***ft_putline_map(char ***map, char *line, int i)
{
	char	*trim;

	if (i % (MAP_SIZE - 1) == 0 && i != 0)
		map = ft_resize_arr(map, i);
	if (line)
		trim = ft_strtrim(line, "\n");
	if (line != NULL && ft_strncmp(trim, "", 2) != 0)
	{
		map[i] = ft_split(trim, ' ');
		free(trim);
	}
	else
	{
		map[i] = NULL;
		return (map);
	}
	return (map);
}

char	***ft_get_map(int fd)
{
	int		i;
	char	*line;
	char	***map;

	map = (char ***)malloc(MAP_SIZE * sizeof(char **));
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map = ft_putline_map(map, line, i);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	map = ft_putline_map(map, line, i);
	return (map);
}

void	fill_xyz_line(char ***map, t_xyz ***map_parsed, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		map_parsed[i][j] = (t_xyz *)malloc(sizeof(t_xyz));
		(map_parsed[i][j])->x = j * 10;
		(map_parsed[i][j])->y = i * 10;
		(map_parsed[i][j])->z = (double)ft_atoi(map[i][j]);
		j++;
	}
	map_parsed[i][j] = NULL;
}

t_xyz	***ft_map_parse(char ***map)
{
	int		i;
	int		line_len;
	t_xyz	***map_parsed;

	line_len = 0;
	i = 0;
	while (map[i])
		i++;
	line_len = get_line_len(map[0]);
	map_parsed = (t_xyz ***)malloc((i + 1) * sizeof(t_xyz **));
	i = 0;
	while (map[i])
	{
		map_parsed[i] = (t_xyz **)malloc((line_len + 1) * sizeof(t_xyz *));
		fill_xyz_line(map, map_parsed, i);
		i++;
	}
	map_parsed[i] = NULL;
	map_clear(map);
	return (map_parsed);
}

void	map_line_check(char ***map)
{
	int	i;
	int	line_len;

	i = 0;
	line_len = get_line_len(map[i]);
	while (map[i])
	{
		if (line_len != get_line_len(map[i]) || !ft_any_digit(map[i]))
		{
			map_clear(map);
			exit(0);
		}
		i++;
	}
}
