/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:46:12 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 04:20:21 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
	@brief Exit with perror

	@param errmsg Error message to be passed to perror
*/
void	exit_perr(char *errmsg)
{
	perror(errmsg);
	exit(EXIT_FAILURE);
}

/**
	@brief Exit with strerr

	@param errcode errno parameter to be passed to strerr. Note
	that this parameter needs to have a name different from
	`errno` to prevent conflicts with the actual macro.
*/
void	exit_strerr(int errcode)
{
	ft_printf("Error: %s\n", strerror(errcode));
	exit(EXIT_FAILURE);
}

/**
	@brief Exit with custom error message

	@param message Error message to be printed
*/
void	exit_custom(char *message)
{
	ft_printf("Error: %s\n", message);
	exit(EXIT_FAILURE);
}

void	validate_file(const char *file_path)
{
	if (open(file_path, O_RDONLY) == -1)
		exit_perr("Unable to access map file");
}
