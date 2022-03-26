/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftonita <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 06:34:03 by ftonita           #+#    #+#             */
/*   Updated: 2022/03/26 06:34:10 by ftonita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# define MAP_SIZE 10

typedef struct s_xyzes
{
	double	x;
	double	y;
	double	z;
}				t_xyz;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fdf {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_xyz	***map;
	t_xyz	*shift;
	float	scale;
}				t_fdf;

typedef struct s_line
{
	t_xyz		*start;
	t_xyz		*end;
	int			dx;
	int			dy;
	t_img		*img;
	int			color;
}				t_line;

int		i_part(double x);
void	swap(t_xyz *s, t_xyz *e);
void	put_pixel_img(t_img *data, int x, int y, int color);
t_xyz	*xyz_copy(t_xyz *p);
void	add_shift(t_xyz *p, t_xyz *shift);
void	to_iso(t_xyz *p);
t_xyz	*point_move(t_xyz *point, t_fdf *fdf);
t_xyz	*get_center(t_xyz ***map);
double	get_map_scale(t_xyz *center);
float	get_peak(t_xyz ***map);
float	get_lowest(t_xyz ***map);
int		ft_any_digit(char **s);
void	map_clear(char ***map);
void	parsedmap_clear(t_xyz ***map);
int		get_line_len(char **map);
char	***ft_resize_arr(char ***map, int map_current_size);
char	***ft_putline_map(char ***map, char *line, int i);
char	***ft_get_map(int fd);
void	fill_xyz_line(char ***map, t_xyz ***map_parsed, int i);
t_xyz	***ft_map_parse(char ***map);
void	map_line_check(char ***map);
void	set_to_center(t_xyz ***map, t_xyz *center);
void	set_size(t_xyz *point, double line_len);
void	print_simple_linex(t_xyz *start_point, t_xyz *end_point,
			t_img *img, int color);
void	print_simple_liney(t_xyz *start_point, t_xyz *end_point,
			t_img *img, int color);
void	print_line_x(t_line *line);
void	print_line_y(t_line *line);
void	print_line(t_line *line);
void	print_two_line(t_fdf *fdf, t_line *line, int i, int j);
void	print_map(t_fdf *fdf);
int		key_hook(int key, t_fdf *info);
int		choose_color(float z);

#endif
