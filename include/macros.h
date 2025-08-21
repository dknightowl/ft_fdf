/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:28:47 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 08:22:34 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define INVALID -1
# define EXIT_FAILURE 1

# define WIN_WIDTH 1000
# define WIN_HEIGHT 800
# define WIN_TITLE "Hello FDF"

# ifndef DEBUG_LOGS_ON
#  define DEBUG_LOGS_ON 0
# endif

# ifndef VERBOSE_LOGS_ON
#  define VERBOSE_LOGS_ON 1
# endif

# define ROT_STEP_SIZE 0.01
# define TRLATE_STEP_SIZE 10
# define SCALE_STEP_SIZE 1
# define MIN_SCALE_LIMIT 2
# define DEFAULT_SCALE 10

# define UNINIT_INT -999999
# define UNINIT_COLOUR -1
# define UNINIT_TYPE 0xDEAD

#endif