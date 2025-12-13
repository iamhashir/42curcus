# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/25 00:32:42 by mhashir           #+#    #+#              #
#    Updated: 2025/08/25 00:46:14 by mhashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		=	unnecessary_violence
CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98
SRC_FILES	=	HumanA.cpp HumanB.cpp main.cpp Weapon.cpp

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	include/

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
