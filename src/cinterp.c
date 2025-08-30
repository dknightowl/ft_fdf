/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cinterp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:01:02 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 08:39:56 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Interpolates colour
*/

/*
	Interpolates colour
*/

static void	clamp_fraction(float *fraction)
{
	if (!fraction)
		exit_perr("Fraction failed");
	if (*fraction < 0.0f)
		*fraction = 0.0f;
	else if (*fraction > 1.0f)
		*fraction = 1.0f;
}

static float	fraction(int x, int a, int b)
{
	if (a == b)
	{
		if (x == a)
			return (0.0f);
		return (-1.0f);
	}
	return ((float)abs((x - a) / (b - a)));
}

static int	rgb_to_int(t_rgb *rgb)
{
	return ((rgb->r << 16) | (rgb->g << 8) | rgb->b);
}

static void	parse_rgb(int rgb_num, t_rgb *rgb)
{
	rgb->r = (rgb_num >> 16) & 0xFF;
	rgb->g = (rgb_num >> 8) & 0xFF;
	rgb->b = rgb_num & 0xFF;
}

int	interpolate_colour(t_point *p0, t_point *p, t_point *p1)
{
	float	frac;
	t_rgb	p0_rgb;
	t_rgb	p_rgb;
	t_rgb	p1_rgb;

	frac = fraction(p->z, p0->z, p1->z);
	clamp_fraction(&frac);
	parse_rgb(p0->colour, &p0_rgb);
	parse_rgb(p1->colour, &p1_rgb);
	p_rgb.r = (unsigned char)((p1_rgb.r - p0_rgb.r) * frac + p0_rgb.r);
	p_rgb.g = (unsigned char)((p1_rgb.g - p0_rgb.g) * frac + p0_rgb.g);
	p_rgb.b = (unsigned char)((p1_rgb.b - p0_rgb.b) * frac + p0_rgb.b);
	return (rgb_to_int(&p_rgb));
}
