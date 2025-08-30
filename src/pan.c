/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pan.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 10:32:08 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/26 12:57:27 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
	@brief Pans the view in cardinal directions (i.e. north(up), south(down),
	east(right), west(left)) via keyboard input

	@param fdf Pointer to struct containing pan states
	@param keycode Key code representing the direction to pan
*/
void	pan_cardinal(t_fdf *fdf, t_keycode keycode)
{
	if (keycode == KEY_W)
		fdf->pan_y -= TRLATE_STEP_SIZE;
	else if (keycode == KEY_S)
		fdf->pan_y += TRLATE_STEP_SIZE;
	else if (keycode == KEY_A)
		fdf->pan_x -= TRLATE_STEP_SIZE;
	else if (keycode == KEY_D)
		fdf->pan_x += TRLATE_STEP_SIZE;
}

/**
	@brief Pans the view freely based on mouse movement

	@param fdf 	Pointer to struct containing pan and mouse states
	@param new_x New x-coordinate of the mouse
	@param new_y New y-coordinate of the mouse
*/
void	pan_freeform(t_fdf *fdf, int new_x, int new_y)
{
	int	dx;
	int	dy;

	dx = new_x - fdf->prev_mouse_x;
	dy = new_y - fdf->prev_mouse_y;
	fdf->pan_x += dx;
	fdf->pan_y += dy;
	fdf->prev_mouse_x = new_x;
	fdf->prev_mouse_y = new_y;
}
