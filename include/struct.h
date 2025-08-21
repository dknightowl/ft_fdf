/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:27:39 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 03:39:04 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "enum.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp; // bits per pixel
	int		llen; // line length
	int		endian;
}	t_data;

typedef struct s_point
{
	t_pointtype	type;
	int			x;
	int			y;
	int			z;
	int			colour;
}	t_point;

typedef struct s_map
{
	int		rows;
	int		max_cols;
	t_point	**points;
}	t_map;

typedef struct s_fdf
{
	// mlx vars
	void			*mlx;
	void			*win;
	t_data			mlx_data;

	// map
	t_map			map;

	// view
	t_projection	projection_mode;
	int				zoom;
	int				pan_x;
	int				pan_y;
	double			rot_x;
	double			rot_y;
	double			rot_z;
	double			altitude_adjust;

	// interactions
	int				is_mouse_press;
	int				prev_mouse_x;
	int				prev_mouse_y;
}	t_fdf;

typedef struct s_bsh
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	i;
}	t_bsh;

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_pparser
{
	int		r;
	int		c;
	char	**tokens;
}	t_pparser;

#endif