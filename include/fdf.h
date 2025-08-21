/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:37:53 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/29 05:26:36 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* libft */
# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "libft.h"
# include "extra.h"

/* fdf libraries */
# include <stdlib.h> // malloc, free, exit
# include <math.h>
# include <fcntl.h> // open, close
# include <unistd.h> // read, write
# include <stdio.h> // perror
# include <string.h> // strerror
# include <errno.h> // for strerror
# include "mlx.h"

/* fdf headers */
# include "macros.h"
# include "enum.h"
# include "struct.h"
# include "utils.h"

// parse
void	parse_map(t_fdf *fdf, const char *file_path);

// project
void	project_iso(t_point *p);
void	project_ortho(t_point *p);
void	toggle_projection(t_fdf *fdf);
void	toggle_altitude(t_fdf *fdf);

// init
void	init_fdf_view(t_fdf *fdf, t_projection projection);
void	init(t_fdf *fdf);
void	toggle_init_fdf_view(t_fdf *fdf, t_keycode keycode);
void	init_pparser(t_pparser *vars);

// bsh
void	render_bsh_line(t_data *mlx_data, t_point *p0, t_point *p1);

// render
void	render_map(t_fdf *fdf);

// pan
void	pan_cardinal(t_fdf *fdf, t_keycode keycode);
void	pan_freeform(t_fdf *fdf, int new_x, int new_y);

// zoom
void	zoom(t_fdf *fdf, t_keycode keycode);

// rotate
void	rotate_x(t_point *p, double angle_rad);
void	rotate_y(t_point *p, double angle_rad);
void	rotate_z(t_point *p, double angle_rad);
void	rotate(t_fdf *fdf, t_keycode keycode);

// colour
int		parse_colour(char *str);
int		interpolate_colour(t_point *p0, t_point *p, t_point *p1);

// hooks
void	register_hooks(t_fdf *fdf);

// sentinels
t_point	point_invalid(void);
t_point	point_none(void);
t_map	empty_map(void);
int		is_point_invalid(t_point p);
int		is_empty_map(t_map m);

// errors
void	exit_perr(char *err_msg);
void	exit_strerr(int errcode);
void	exit_custom(char *message);
void	validate_file(const char *file_path);

// log
void	log_fdf(t_fdf *fdf);

#endif
