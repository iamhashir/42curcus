# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 02:29:43 by mhashir           #+#    #+#              #
#    Updated: 2024/07/06 03:41:56 by mhashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FILES = mouse_keyhooks.c keyhooks.c handle_pixel.c initialization.c julia.c main.c utils2.c render.c utils.c 

OBJ = $(FILES:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all :$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ)  -I./mlx -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(FILES)

.PHONY: all clean fclean re