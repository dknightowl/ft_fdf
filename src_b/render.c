/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:06:19 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 21:47:17 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Functions to render map image
*/

static t_point	adjusted_point(t_fdf *fdf, t_point *p)
{
	t_point	p_cpy;
	int		offset_x;
	int		offset_y;

	p_cpy = *p;
	p_cpy.z *= fdf->altitude_adjust;
	p_cpy.x *= fdf->zoom;
	p_cpy.y *= fdf->zoom;
	p_cpy.z *= fdf->zoom;
	rotate_x(&p_cpy, fdf->rot_x);
	rotate_y(&p_cpy, fdf->rot_y);
	rotate_z(&p_cpy, fdf->rot_z);
	if (fdf->projection_mode == PROJECT_ISO)
		project_iso(&p_cpy);
	else if (fdf->projection_mode == PROJECT_ORTHO)
		project_ortho(&p_cpy);
	offset_x = WIN_WIDTH / 2;
	offset_y = (WIN_HEIGHT - fdf->map.rows * fdf->zoom) / 2;
	p_cpy.x += offset_x;
	p_cpy.y += offset_y;
	p_cpy.x += fdf->pan_x;
	p_cpy.y += fdf->pan_y;
	return (p_cpy);
}

static void	render_line(t_fdf *fdf, t_point *p0, t_point *p1)
{
	t_point	p0_cpy;
	t_point	p1_cpy;

	p0_cpy = adjusted_point(fdf, p0);
	p1_cpy = adjusted_point(fdf, p1);
	render_bsh_line(&fdf->mlx_data, &p0_cpy, &p1_cpy);
}

/*
	This is being called continuously in a loop in `display`
*/
void	render_map(t_fdf *fdf)
{
	int	col;
	int	r_idx;

	r_idx = 0;
	while (r_idx < fdf->map.rows)
	{
		col = -1;
		while (++col < fdf->map.max_cols)
		{
			if (col < (fdf->map.max_cols - 1))
			{
				if (fdf->map.points[r_idx][col + 1].type != POINT_NORMAL)
					break ;
				else
					render_line(fdf, &fdf->map.points[r_idx][col],
						&fdf->map.points[r_idx][col + 1]);
			}
			if (r_idx < (fdf->map.rows - 1)
				&& fdf->map.points[r_idx + 1][col].type == POINT_NORMAL)
				render_line(fdf, &fdf->map.points[r_idx][col],
					&fdf->map.points[r_idx + 1][col]);
		}
		r_idx++;
	}
}
