# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/9/28 12:00:49 by mhashir           #+#    #+#              #
#    Updated: 2024/9/28 02:55:40 by mhashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

SRC = main.c utils.c init.c threads.c monitor.c routine_actions.c

MANPATH = $(addprefix ./src/, $(SRC))

FLAGS = -Wall -Wextra -Werror -O3 -pthread

HEADER = ./src/philo.h

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(MANPATH) $(HEADER)
	@cc $(FLAGS) -o $(NAME) $(MANPATH) $(SANITIZER)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

debug: FLAGS += -g
debug: re
