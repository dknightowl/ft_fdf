/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:52:34 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 04:28:04 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Register hooks for event handling
	- https://github-wiki-see.page/m/codam-coding-college/MLX42/wiki/Hooks
*/

static int	on_keypress(t_keycode keycode, t_fdf *fdf)
{
	if (keycode == KEY_0 || keycode == KEY_1)
		toggle_init_fdf_view(fdf, keycode);
	else if (keycode == KEY_TAB)
		toggle_projection(fdf);
	else if (keycode == KEY_CAPS)
		toggle_altitude(fdf);
	else if (keycode == KEY_ESC)
		mlx_cleanup(fdf);
	else if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		pan_cardinal(fdf, keycode);
	else if (keycode == ARROW_UP || keycode == ARROW_DOWN
		|| keycode == ARROW_LEFT || keycode == ARROW_RIGHT
		|| keycode == KEY_LESSTHAN || keycode == KEY_MORETHAN)
		rotate(fdf, keycode);
	else if (keycode == KEY_MINUS || keycode == KEY_PLUS)
		zoom(fdf, keycode);
	else
		ft_printf("(on_keypress) unhandled keycode: %d\n", keycode);
	return (0);
}

static int	on_btnaction(t_keycode keycode, int x, int y, t_fdf *fdf)
{
	if (keycode == SCROLL_UP || keycode == SCROLL_DOWN)
		zoom(fdf, keycode);
	else if (keycode == LEFT_CLICK)
	{
		if (fdf->is_mouse_press == 0)
		{
			fdf->prev_mouse_x = x;
			fdf->prev_mouse_y = y;
		}
		fdf->is_mouse_press ^= 1;
	}
	else
		ft_printf("(on_btnaction) unhandled keycode:%d\n", keycode);
	return (0);
}

static int	on_mousemove(int x, int y, t_fdf *fdf)
{
	if (fdf->is_mouse_press == 1)
		pan_freeform(fdf, x, y);
	return (0);
}

void	register_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, KEYPRESS, KEYPRESS_MASK, on_keypress, fdf);
	mlx_hook(fdf->win, BUTTONPRESS, BUTTONPRESS_MASK, on_btnaction, fdf);
	mlx_hook(fdf->win, BUTTONRELEASE, BUTTONRELEASE_MASK, on_btnaction, fdf);
	mlx_hook(fdf->win, MOTIONNOTIFY, POINTERMOTION_MASK, on_mousemove, fdf);
	mlx_hook(fdf->win, DESTROYNOTIFY, NOEVENT_MASK, mlx_cleanup, fdf);
	mlx_loop_hook(fdf->mlx, mlx_display, fdf);
}
