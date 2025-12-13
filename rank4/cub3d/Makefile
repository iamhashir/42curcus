# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 15:37:39 by mhashir          #+#    #+#              #
#    Updated: 2025/07/27 03:01:56 by mhashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS = main.c \
		parse/free.c \
		parse/mallocs.c \
		parse/map_analysis.c \
		parse/map_validity_check.c \
		parse/parsing.c \
		parse/start_game_loop.c \
		parse/utils.c \
		parse/validation.c \
		parse/vars_analysis.c \
		exec/draw_vertical_line.c \
		exec/init_map.c \
		exec/map_config.c \
		exec/key_press.c \
		exec/movements.c \
		exec/raycast.c \
		exec/set_map.c \
		exec/set_player.c \
		libft/ft_strnstr.c \

OBJS = $(SRCS:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	make -C libft
	make -C mlx
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	@if [ -d "mlx" ]; then \
		make clean -C mlx; \
	fi
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all
