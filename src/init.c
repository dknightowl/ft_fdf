/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:56:42 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/29 05:29:24 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Initialize fdf variables
*/

void	toggle_init_fdf_view(t_fdf *fdf, t_keycode keycode)
{
	if (keycode == KEY_0)
		init_fdf_view(fdf, PROJECT_ISO);
	else if (keycode == KEY_1)
		init_fdf_view(fdf, PROJECT_ORTHO);
}

void	init_fdf_view(t_fdf *fdf, t_projection projection)
{
	fdf->projection_mode = projection;
	fdf->zoom = DEFAULT_SCALE;
	fdf->pan_x = 0;
	fdf->pan_y = 0;
	fdf->rot_x = 0;
	fdf->rot_y = 0;
	fdf->rot_z = 0;
	fdf->altitude_adjust = 1;
}

static void	init_fdf_interactions(t_fdf *fdf)
{
	fdf->is_mouse_press = 0;
	fdf->prev_mouse_x = INVALID;
	fdf->prev_mouse_y = INVALID;
}

// ft_memset(fdf, 0, sizeof(t_fdf));
void	init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		exit_strerr(errno);
	fdf->mlx_data.img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->mlx_data.addr = mlx_get_data_addr(fdf->mlx_data.img,
			&fdf->mlx_data.bpp,
			&fdf->mlx_data.llen,
			&fdf->mlx_data.endian);
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!fdf->win)
		exit_strerr(errno);
	fdf->map = empty_map();
	init_fdf_view(fdf, PROJECT_DEFAULT);
	init_fdf_interactions(fdf);
}

void	init_pparser(t_pparser *vars)
{
	vars->r = 0;
	vars->c = 0;
	vars->tokens = NULL;
}
