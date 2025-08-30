/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mparser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 01:51:39 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 21:42:00 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Map parser. Parses fdf maps into structs. Maps must be correctly formatted.
*/

static void	parse_tokens(char *line, char ***tokens)
{
	if (*tokens)
		free_split(*tokens);
	if (!line)
		*tokens = NULL;
	else
	{
		*tokens = ft_split(line, ' ');
		free(line);
	}
}

static void	parse_point(const char *entry, int x, int y, t_point *points_loc)
{
	t_point	p;
	char	**info;

	p = point_invalid();
	p.type = POINT_NORMAL;
	p.x = x;
	p.y = y;
	info = ft_split(entry, ',');
	if (!info)
	{
		p = point_invalid();
		return ;
	}
	p.z = ft_atoi(info[0]);
	colour_point(info[1], &p);
	free_split(info);
	ft_memcpy(points_loc, &p, sizeof(t_point));
}

static void	pad_row(t_point **points, int r_idx, int c_idx, int cols)
{
	while (c_idx < cols)
	{
		points[r_idx][c_idx] = point_none();
		c_idx++;
	}
}

static t_point	**parse_points(int fd, int rows, int cols)
{
	t_pparser	vrs;
	t_point		**points;

	points = (t_point **) alloc_2d(sizeof(t_point), rows, cols);
	if (!points)
		return (NULL);
	init_pparser(&vrs);
	while (vrs.r < rows)
	{
		parse_tokens(get_next_line(fd), &vrs.tokens);
		if (!vrs.tokens)
			return (free_2d((void **) points, vrs.r), NULL);
		vrs.c = 0;
		while (vrs.c < cols && vrs.tokens[vrs.c])
		{
			parse_point(vrs.tokens[vrs.c], vrs.c, vrs.r, points[vrs.r] + vrs.c);
			if (is_point_invalid(points[vrs.r][vrs.c]))
				return (free_split(vrs.tokens),
					free_2d((void **) points, vrs.r + 1), NULL);
			vrs.c++;
		}
		pad_row(points, vrs.r, vrs.c, cols);
		vrs.r++;
	}
	return (free_split(vrs.tokens), points);
}

void	parse_map(t_fdf *fdf, const char *file_path)
{
	t_map	map;
	int		fd;

	fd = open(file_path, O_RDONLY);
	map.rows = count_fd_rows(fd);
	fd = open(file_path, O_RDONLY);
	map.max_cols = count_fd_max_cols(fd);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		exit_strerr(errno);
	map.points = parse_points(fd, map.rows, map.max_cols);
	close(fd);
	if (!map.points)
		exit_perr("Failed to parse map points");
	fdf->map = map;
}
