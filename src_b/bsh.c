/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 04:21:46 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 08:39:29 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Implementation of Bresenham's Line Algorithm
*/

/**
	@brief Determines direction between two coordinates

	@param p0_xy x or y-coordinate of starting point
	@param p1_xy x or y-coordinate of ending point

	@return If p1 coordinate is greater than p0's, returns 1.
	Otherwise, returns -1
*/
static int	xy_direction(int p0_xy, int p1_xy)
{
	if (p0_xy < p1_xy)
		return (1);
	return (-1);
}

/**
	@brief Initializes parameters for Bresenham's line algorithm.
	Calculates deltas (change in coordinates), step directions, and error
	term for drawing a line between two points.

	@param bsh Pointer to struct containing state variables for the algorithm
	@param p0 Pointer to the starting point
	@param p1 Pointer to the ending point
*/
static void	init_bsh(t_bsh *bsh, t_point *p0, t_point *p1)
{
	bsh->dx = abs(p1->x - p0->x);
	bsh->dy = abs(p1->y - p0->y);
	bsh->sx = xy_direction(p0->x, p1->x);
	bsh->sy = xy_direction(p0->y, p1->y);
	bsh->err = bsh->dx - bsh->dy;
	bsh->i = 0;
}

/**
	@brief Linear interpolation of Z value for a point between the starting
	and ending point. Uses the curent step index and total steps to calculate
	the interpolated Z-coordinate.

	@param bsh Pointer to struct containing progress state variables for
	the Bresenham algorithm
	@param p0_z Z coordinate of starting point
	@param p1_z Z coordinate of ending point

	@return Interpolated Z coordinate of the point at the current step
*/
static int	interpolate_z(t_bsh *bsh, int p0_z, int p1_z)
{
	int		steps;
	float	t;

	if (bsh->dx > bsh->dy)
		steps = bsh->dx;
	else
		steps = bsh->dy;
	if (steps == 0)
		t = 0.0f;
	else
		t = (float) bsh->i / steps;
	return ((int)((1.0f - t) * p0_z + t * p1_z));
}

/**
	@brief Updates x and y coordinates based on Bresenham's decision rule.
	Adjusts error term and increments x and/or y-coordinate based on current
	error and step directions.

	@param bsh Pointer to struct containing Bresenham state variables
	for decision rule
	@param x Pointer to current x-coordinate
	@param y Pointer to current y-coordinate
*/
static void	bsh_decision(t_bsh *bsh, int *x, int *y)
{
	int	e2;

	e2 = 2 * bsh->err;
	if (e2 > -bsh->dy)
	{
		bsh->err -= bsh->dy;
		*x += bsh->sx;
	}
	if (e2 < bsh->dx)
	{
		bsh->err += bsh->dx;
		*y += bsh->sy;
	}
}

/**
	@brief Main implementation of Bresenham's Line Algorithm. Renders a 
	line from a starting point to an ending point.

	@param mlx_data Pointer to struct containing contextual information
	for interacting with MLX library
	@param p0 Start point to draw the line from
	@param p1 End point to draw the line until
*/
void	render_bsh_line(t_data *mlx_data, t_point *p0, t_point *p1)
{
	t_bsh	bsh;
	t_point	p;
	int		x;
	int		y;

	init_bsh(&bsh, p0, p1);
	x = p0->x;
	y = p0->y;
	p = point_invalid();
	while (1)
	{
		p.type = POINT_NORMAL;
		p.x = x;
		p.y = y;
		p.z = interpolate_z(&bsh, p0->z, p1->z);
		p.colour = interpolate_colour(p0, &p, p1);
		my_mlx_pixel_put(mlx_data, &p);
		if (x == p1->x && y == p1->y)
			break ;
		bsh_decision(&bsh, &x, &y);
		bsh.i++;
	}
}
