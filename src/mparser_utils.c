/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mparser_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:47:59 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 20:19:32 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Utility functions for map parser
*/

int	count_fd_rows(int fd)
{
	int		idx;
	char	*line;

	if (fd < 0)
		exit_strerr(errno);
	idx = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		idx++;
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		exit_strerr(errno);
	return (idx);
}

int	count_cols(char *line, char delimiter)
{
	int		idx;
	char	**arr;

	arr = ft_split(line, delimiter);
	if (!arr)
		return (INVALID);
	idx = 0;
	while (arr[idx])
		idx++;
	free_split(arr);
	return (idx);
}

int	count_fd_max_cols(int fd)
{
	int		max;
	int		cols;
	char	*line;

	if (fd < 0)
		exit_strerr(errno);
	max = 0;
	line = NULL;
	while (1)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		cols = count_cols(line, ' ');
		if (cols > max)
			max = cols;
	}
	if (close(fd) == -1)
		exit_strerr(errno);
	return (max);
}

void	colour_point(char *colour_s, t_point *p)
{
	if (colour_s)
	{
		p->colour = parse_colour(colour_s);
		if (p->colour == UNINIT_COLOUR)
			p->colour = COLOR_DEFAULT;
	}
	else if (p->z > 0)
		p->colour = COLOR_HIGH;
	else if (p->z < 0)
		p->colour = COLOR_LOW;
	else
		p->colour = COLOR_DEFAULT;
}
