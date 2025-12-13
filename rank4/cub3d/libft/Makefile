# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/22 22:35:26 by mhashir           #+#    #+#              #
#    Updated: 2025/08/22 22:35:28 by mhashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a
CC			= cc
CFLAGS 		= -Wall -Wextra -Werror
SRCS = ft_atoi.c  ft_putchar_fd.c ft_isdigit.c\
      ft_memset.c ft_strchr.c  ft_strlcpy.c ft_strncmp.c \
	  ft_strlen.c ft_split.c ft_substr.c ft_memcpy.c\
	  ft_putstr_fd.c ft_strdup.c ft_strjoin.c\

OBJECTS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all, clean, fclean, re
