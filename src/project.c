/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:38:02 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 03:43:15 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Projections for map points. Plotted points are
	rearranged to simulate projections.
*/

/**
	@brief Isometric projection for a single point

	@param p Point to project
*/
void	project_iso(t_point *p)
{
	int	original_x;
	int	original_y;

	original_x = p->x;
	original_y = p->y;
	p->x = (original_x - original_y) * cos(0.523599);
	p->y = (original_x + original_y) * sin(0.523599) - p->z;
}

/**
	@brief Top-down orthogonal projection for a single point

	@param p Point to project
*/
void	project_ortho(t_point *p)
{
	p->z = 0;
}

/**
	@brief

	@param fdf
*/
void	toggle_projection(t_fdf *fdf)
{
	if (fdf->projection_mode == PROJECT_ISO)
		fdf->projection_mode = PROJECT_ORTHO;
	else
		fdf->projection_mode = PROJECT_ISO;
}

void	toggle_altitude(t_fdf *fdf)
{
	if (fdf->altitude_adjust == 1)
		fdf->altitude_adjust = 0.5;
	else if (fdf->altitude_adjust == 0.5)
		fdf->altitude_adjust = 1.5;
	else if (fdf->altitude_adjust == 1.5)
		fdf->altitude_adjust = 2;
	else
		fdf->altitude_adjust = 1;
}
