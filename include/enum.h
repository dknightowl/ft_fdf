/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:39:58 by dkhoo             #+#    #+#             */
/*   Updated: 2025/07/28 04:56:34 by dkhoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_color
{
	COLOR_PRIMARY_RED = 0xFF0000,
	COLOR_WHITE = 0xFFFFFF,
	COLOR_SKY_BLUE = 0x66CCFF,
	COLOR_BRIGHT_BLUE = 0x0099CC,
	COLOR_DEEP_TEAL_BLUE = 0x006699,
	COLOR_DULL_LIME_GREEN = 0x97B067,
	COLOR_DEEP_FOREST_GREEN = 0x437057,
	COLOR_PINE_GREEN = 0x2F5249,
	COLOR_HIGH = COLOR_DULL_LIME_GREEN,
	COLOR_DEFAULT = COLOR_DEEP_FOREST_GREEN,
	COLOR_LOW = COLOR_PINE_GREEN
}	t_color;

// x11 events (https://harm-smits.github.io/42docs/libs/minilibx/events.html)
typedef enum e_event
{
	KEYPRESS = 2,
	BUTTONPRESS = 4,
	BUTTONRELEASE = 5,
	MOTIONNOTIFY = 6,
	DESTROYNOTIFY = 17
}	t_event;

typedef enum e_eventmask
{
	NOEVENT_MASK = 0L,
	KEYPRESS_MASK = 1L << 0,
	BUTTONPRESS_MASK = 1L << 2,
	BUTTONRELEASE_MASK = 1L << 3,
	POINTERMOTION_MASK = 1L << 6
}	t_eventmask;

typedef enum e_keycode
{
	ARROW_UP = 65362,
	KEY_W = 119,
	ARROW_LEFT = 65361,
	KEY_A = 97,
	ARROW_DOWN = 65364,
	KEY_S = 115,
	ARROW_RIGHT = 65363,
	KEY_D = 100,
	KEY_LESSTHAN = 44,
	KEY_MORETHAN = 46,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5,
	LEFT_CLICK = 1,
	RIGHT_CLICK = 3,
	KEY_0 = 48,
	KEY_1 = 49,
	KEY_MINUS = 45,
	KEY_PLUS = 61,
	KEY_ESC = 65307,
	KEY_TAB = 65289,
	KEY_CAPS = 65509
}	t_keycode;

typedef enum e_projection
{
	PROJECT_ISO = 0,
	PROJECT_ORTHO = 1,
	PROJECT_DEFAULT = PROJECT_ISO
}	t_projection;

typedef enum e_pointtype
{
	POINT_NORMAL = 0,
	POINT_NONE = 1,
	POINT_ERROR = 2
}	t_pointtype;

#endif