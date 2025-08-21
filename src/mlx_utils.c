/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 03:26:48 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 08:23:08 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Utility functions to interface with MLX libary
*/

int	mlx_cleanup(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->mlx_data.img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	if (fdf->map.points)
		free_2d((void **) fdf->map.points, fdf->map.rows);
	exit(EXIT_SUCCESS);
}

void	my_mlx_pixel_put(t_data *mlx_data, t_point *p)
{
	char	*dst;

	if ((p->x >= 0 && p->x < WIN_WIDTH) && (p->y >= 0 && p->y < WIN_HEIGHT))
	{
		dst = mlx_data->addr
			+ (p->y * mlx_data->llen
				+ (p->x * (mlx_data->bpp / 8)));
		*(unsigned int *) dst = p->colour;
	}
}

int	mlx_display(t_fdf *fdf)
{
	ft_bzero(fdf->mlx_data.addr,
		WIN_HEIGHT * WIN_WIDTH * (fdf->mlx_data.bpp / 8));
	render_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->mlx_data.img, 0, 0);
	return (0);
}

// start event loop - continuously checks for events
// and calls registered hook functions
void	init_mlx_loop(t_fdf *fdf)
{
	mlx_loop(fdf->mlx);
}
