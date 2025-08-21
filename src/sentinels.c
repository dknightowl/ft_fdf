/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentinels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:34:29 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 20:45:28 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Sentinels and their checkers
*/

/* SENTINELS */

t_point	point_invalid(void)
{
	t_point	p;

	p.type = UNINIT_TYPE;
	p.x = UNINIT_INT;
	p.y = UNINIT_INT;
	p.z = UNINIT_INT;
	p.colour = UNINIT_COLOUR;
	return (p);
}

t_point	point_none(void)
{
	t_point	p;

	ft_bzero(&p, sizeof(t_point));
	p.type = POINT_NONE;
	return (p);
}

t_map	empty_map(void)
{
	t_map	m;

	m.rows = INVALID;
	m.max_cols = INVALID;
	m.points = NULL;
	return (m);
}

/* CHECKERS */

int	is_point_invalid(t_point p)
{
	return (
		p.type == UNINIT_TYPE
		&& p.x == UNINIT_INT
		&& p.y == UNINIT_INT
		&& p.z == UNINIT_INT
		&& p.colour == UNINIT_COLOUR
	);
}

int	is_empty_map(t_map m)
{
	return (m.rows == INVALID
		&& m.max_cols == INVALID
		&& m.points == NULL);
}
