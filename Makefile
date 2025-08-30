# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhoo <dkhoo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 02:35:44 by dkhoo             #+#    #+#              #
#    Updated: 2025/08/30 20:50:20 by dkhoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc
CCFLAGS = -Wall -Wextra -Werror
DEBUG_FLAG = -g -O0

# minilibx
MLX_DIR = lib/minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
MLX_LIB_LINUX = $(MLX_DIR)/libmlx_Linux.a
MLX_LIB = $(MLX_DIR)/libmlx.a

# libft
# -lft flag tells the linker to look for libft.a or libft.so
LIBFT_DIR = lib/libft
LIBFT = -L$(LIBFT_DIR) -lft
LIBFT_INCLUDE_DIR = $(LIBFT_DIR)/includes
LIBFT_HEADER = $(LIBFT_INCLUDE_DIR)/libft.h $(LIBFT_INCLUDE_DIR)/ft_printf.h $(LIBFT_INCLUDE_DIR)/get_next_line_bonus.h $(LIBFT_INCLUDE_DIR)/extra.h
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# fdf
FDF_INCLUDE_DIR = include
FDF_HEADER_FILES = enum.h fdf.h macros.h struct.h utils.h
FDF_HEADERS = $(addprefix $(FDF_INCLUDE_DIR)/, $(FDF_HEADER_FILES))
INCLUDES = -I$(FDF_INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR) -I$(MLX_DIR)

# mandatory
# SRCS_DIR = src
# SRC_FILES = bsh.c\
# 			cinterp.c\
# 			cparser.c\
# 			errors.c\
# 			hooks.c\
# 			init.c\
# 			log.c\
# 			main.c\
# 			mem_utils.c\
# 			mlx_utils.c\
# 			mparser_utils.c\
# 			mparser.c\
# 			project.c\
# 			render.c\
# 			sentinels.c
# SRCS = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
# OBJS = $(SRCS:.c=.o)

# bonus
SRCS_DIR = src
SRC_FILES = bsh.c\
			cinterp.c\
			cparser.c\
			errors.c\
			hooks.c\
			init.c\
			log.c\
			main.c\
			mem_utils.c\
			mlx_utils.c\
			mparser_utils.c\
			mparser.c\
			pan.c\
			project.c\
			render.c\
			rotate.c\
			sentinels.c\
			zoom.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

# -c: Compile only (no linking)
# $< - 1st prerequisite
# $@ - represents target
# do not add lib dependencies here - they are only needed during linking
$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c $(FDF_HEADERS) $(LIBFT_HEADER)
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR) all

clean:
	rm -rf $(OBJS)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

MAPS =	10-2 10-70 20-60 42 50-4 100-6\
		basictest elem-col elem-fract elem elem2\
		julia mars pentenegpos plat pnp_flat pylone\
		pyra pyramide t1 t2\
		bad-noperm

$(MAPS): %: all
	./fdf "maps/$@.fdf"

.PHONY: all clean fclean re $(MAPS)
