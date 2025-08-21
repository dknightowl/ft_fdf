/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cparser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:32:27 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/26 10:13:32 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Colour parser
*/

static int	check_valid_rgb(int value)
{
	return (value >= 0x000000 && value <= 0xFFFFFF);
}

int	parse_colour(char *str)
{
	int		colour;
	char	*endptr;

	endptr = NULL;
	colour = (int) ft_strtol(str, &endptr, 16);
	if (check_valid_rgb(colour))
		return (colour);
	else
		return (INVALID);
}
