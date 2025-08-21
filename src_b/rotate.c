/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 03:44:53 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/26 12:51:24 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
	@brief Rotates a point about the x-axis

	@param p
	@param angle_rad

	@return None.
*/
void	rotate_x(t_point *p, double angle_rad)
{
	double	original_y;
	double	original_z;

	original_y = p->y;
	original_z = p->z;
	p->y = original_y * cos(angle_rad) - original_z * sin(angle_rad);
	p->z = original_y * sin(angle_rad) + original_z * cos(angle_rad);
}

/**
	@brief Rotates a point about the y-axis

	@param p
	@param angle_rad
*/
void	rotate_y(t_point *p, double angle_rad)
{
	double	original_x;
	double	original_z;

	original_x = p->x;
	original_z = p->z;
	p->x = original_x * cos(angle_rad) + original_z * sin(angle_rad);
	p->z = -original_x * sin(angle_rad) + original_z * cos(angle_rad);
}

// Rotate a point around the Z-axis
void	rotate_z(t_point *p, double angle_rad)
{
	double	original_x;
	double	original_y;

	original_x = p->x;
	original_y = p->y;
	p->x = original_x * cos(angle_rad) - original_y * sin(angle_rad);
	p->y = original_x * sin(angle_rad) + original_y * cos(angle_rad);
}

void	rotate(t_fdf *fdf, t_keycode keycode)
{
	if (keycode == ARROW_UP)
		fdf->rot_x += ROT_STEP_SIZE;
	else if (keycode == ARROW_DOWN)
		fdf->rot_x -= ROT_STEP_SIZE;
	else if (keycode == ARROW_LEFT)
		fdf->rot_y -= ROT_STEP_SIZE;
	else if (keycode == ARROW_RIGHT)
		fdf->rot_y += ROT_STEP_SIZE;
	else if (keycode == KEY_LESSTHAN)
		fdf->rot_z -= ROT_STEP_SIZE;
	else if (keycode == KEY_MORETHAN)
		fdf->rot_z += ROT_STEP_SIZE;
}
