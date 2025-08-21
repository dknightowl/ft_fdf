/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:38:02 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 04:25:48 by dkhoo            ###   ########.fr       */
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
