# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 03:52:07 by mhashir           #+#    #+#              #
#    Updated: 2025/08/24 03:58:10 by mhashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Zombie
CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/

SRC_FILES	=	main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re