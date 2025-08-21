/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 03:19:35 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/26 01:07:12 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// scale up/down
/**
	@brief Adjusts zoom factor. Zooming in/out corresponds to
	scaling up/down. A clamp is imposed when scaling down to
	avoid the image becoming too small to see.

	@param fdf Struct containing zoom factor variable
	@param zoom Whether to zoom in/out
*/
void	zoom(t_fdf *fdf, t_keycode keycode)
{
	if (keycode == SCROLL_UP || keycode == KEY_PLUS)
		fdf->zoom += SCALE_STEP_SIZE;
	else if (keycode == SCROLL_DOWN || keycode == KEY_MINUS)
	{
		if ((fdf->zoom - SCALE_STEP_SIZE) < MIN_SCALE_LIMIT)
			return ;
		fdf->zoom -= SCALE_STEP_SIZE;
	}
}
