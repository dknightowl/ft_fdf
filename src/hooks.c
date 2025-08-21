/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:52:34 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 04:27:57 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Register hooks for event handling
	- https://github-wiki-see.page/m/codam-coding-college/MLX42/wiki/Hooks
*/

static int	on_keypress(t_keycode keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		mlx_cleanup(fdf);
	else
		ft_printf("(on_keypress) unhandled keycode: %d\n", keycode);
	return (0);
}

void	register_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, KEYPRESS, KEYPRESS_MASK, on_keypress, fdf);
	mlx_hook(fdf->win, DESTROYNOTIFY, NOEVENT_MASK, mlx_cleanup, fdf);
	mlx_loop_hook(fdf->mlx, mlx_display, fdf);
}
