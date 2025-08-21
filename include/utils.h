/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:54:44 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 04:24:17 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// mem_utils
void	free_split(char **arr);
void	free_2d(void **arr, int filled_r_idx);
void	**alloc_2d(size_t type_size, int rows, int cols);

// mparser_utils
int		count_fd_rows(int fd);
int		count_cols(char *line, char delimiter);
int		count_fd_max_cols(int fd);
void	colour_point(char *colour_s, t_point *p);

// mlx_utils
int		mlx_cleanup(t_fdf *fdf);
void	my_mlx_pixel_put(t_data *mlx_data, t_point *p);
int		mlx_display(t_fdf *fdf);
void	init_mlx_loop(t_fdf *fdf);

#endif