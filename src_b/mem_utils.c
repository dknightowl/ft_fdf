/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 09:56:03 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/26 12:51:45 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	Memory management utility functions
*/

void	free_split(char **arr)
{
	char	**tmp;

	if (!arr)
		return ;
	tmp = arr;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(arr);
}

void	free_2d(void **arr, int filled_r_idx)
{
	int	idx;

	if (!arr || filled_r_idx < 0)
		return ;
	idx = 0;
	while (idx < filled_r_idx)
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
}

void	**alloc_2d(size_t type_size, int rows, int cols)
{
	void	**arr_ptrs;
	int		r_idx;

	arr_ptrs = malloc(sizeof(void *) * rows);
	if (!arr_ptrs)
		return (NULL);
	r_idx = 0;
	while (r_idx < rows)
	{
		arr_ptrs[r_idx] = malloc(type_size * cols);
		if (!arr_ptrs[r_idx])
		{
			free_2d(arr_ptrs, r_idx);
			return (NULL);
		}
		r_idx++;
	}
	return (arr_ptrs);
}
