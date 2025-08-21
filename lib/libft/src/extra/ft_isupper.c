/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:47:42 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/11 11:50:15 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
	@brief Returns whether or not c is an uppercase letter

	@param c The character to check

	@return
*/
int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
