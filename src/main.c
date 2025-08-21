/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:43:07 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 07:32:15 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc != 2)
		exit_custom("Incorrect arguments. Correct Format: ./fdf [path/to/map]");
	validate_file(argv[1]);
	ft_printf("Generating map: %s...\n", argv[1]);
	init(&fdf);
	parse_map(&fdf, argv[1]);
	if (DEBUG_LOGS_ON)
		log_fdf(&fdf);
	register_hooks(&fdf);
	init_mlx_loop(&fdf);
	mlx_display(&fdf);
	return (SUCCESS);
}
