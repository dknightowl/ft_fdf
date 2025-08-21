/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 10:09:20 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 21:05:36 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Log functions for debugging
*/

static void	log_mlx_data(t_data data)
{
	ft_printf("t_data:\n");
	ft_printf("  img: %p\n", data.img);
	if (data.addr)
		ft_printf("  addr: %s\n", data.addr);
	else
		ft_printf("  addr: %s\n", "(null)");
	ft_printf("  bpp: %d\n", data.bpp);
	ft_printf("  llen: %d\n", data.llen);
	ft_printf("  endian: %d\n", data.endian);
}

static void	log_point(t_point p, int r_idx, int c_idx)
{
	ft_printf("[%03d][%03d]:", r_idx, c_idx);
	if (p.type == POINT_NONE)
		ft_printf("(end of row)\n");
	else
	{
		if (is_point_invalid(p))
			ft_printf("INVALID: {type=%d, x=%d, y=%d, z=%d, colour=0x%X}\n",
				p.type, p.x, p.y, p.z, p.colour);
	}
}

static void	log_map(t_map map)
{
	int	r_idx;
	int	c_idx;

	ft_printf("\n== logging map... ==\n");
	ft_printf("   rows:%d, max_cols:%d\n", map.rows, map.max_cols);
	if (map.points == NULL)
	{
		perror("map.points are NULL.\n");
		return ;
	}
	r_idx = 0;
	while (r_idx < map.rows && VERBOSE_LOGS_ON)
	{
		c_idx = 0;
		while (c_idx < map.max_cols)
		{
			log_point(map.points[r_idx][c_idx], r_idx, c_idx);
			c_idx++;
		}
		r_idx++;
	}
	ft_printf("\n== end logging map ==\n");
}

void	log_fdf(t_fdf *fdf)
{
	if (!fdf)
	{
		ft_printf("fdf is NULL\n");
		return ;
	}
	ft_printf("t_fdf:\n");
	ft_printf("  mlx: %p\n", fdf->mlx);
	ft_printf("  win: %p\n", fdf->win);
	log_mlx_data(fdf->mlx_data);
	ft_printf("  projection_mode: %d\n", fdf->projection_mode);
	ft_printf("t_map:\n");
	log_map(fdf->map);
	ft_printf(">> end of log.");
}
