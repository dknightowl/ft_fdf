/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:56:42 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/29 05:28:41 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Initialize fdf variables
*/

void	init_fdf_view(t_fdf *fdf, t_projection projection)
{
	fdf->projection_mode = projection;
}

void	init(t_fdf *fdf)
{
	ft_memset(fdf, 0, sizeof(t_fdf));
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
}

void	init_pparser(t_pparser *vars)
{
	vars->r = 0;
	vars->c = 0;
	vars->tokens = NULL;
}
